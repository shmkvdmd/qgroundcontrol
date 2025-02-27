/****************************************************************************
 *
 * (c) 2009-2024 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/


/// @file
///     @author Don Gagne <don@thegagnes.com>

#include "AutoPilotPlugin.h"
#include "QGCApplication.h"
#include "FirmwarePlugin.h"
#include "Vehicle.h"
#include "VehicleComponent.h"
#include <QtCore/QCoreApplication>

AutoPilotPlugin::AutoPilotPlugin(Vehicle* vehicle, QObject* parent)
    : QObject(parent)
    , _vehicle(vehicle)
    , _firmwarePlugin(vehicle->firmwarePlugin())
    , _setupComplete(false)
{

}

AutoPilotPlugin::~AutoPilotPlugin()
{

}

void AutoPilotPlugin::_recalcSetupComplete(void)
{
    bool newSetupComplete = true;

    for(const QVariant& componentVariant: vehicleComponents()) {
        VehicleComponent* component = qobject_cast<VehicleComponent*>(qvariant_cast<QObject *>(componentVariant));
        if (component) {
            if (!component->setupComplete()) {
                newSetupComplete = false;
                break;
            }
        } else {
            qWarning() << "AutoPilotPlugin::_recalcSetupComplete Incorrectly typed VehicleComponent";
        }
    }

    if (_setupComplete != newSetupComplete) {
        _setupComplete = newSetupComplete;
        emit setupCompleteChanged();
    }
}

bool AutoPilotPlugin::setupComplete(void) const
{
    return _setupComplete;
}

void AutoPilotPlugin::parametersReadyPreChecks(void)
{
    _recalcSetupComplete();

    // Connect signals in order to keep setupComplete up to date
    for(QVariant componentVariant: vehicleComponents()) {
        VehicleComponent* component = qobject_cast<VehicleComponent*>(qvariant_cast<QObject *>(componentVariant));
        if (component) {
            connect(component, &VehicleComponent::setupCompleteChanged, this, &AutoPilotPlugin::_recalcSetupComplete);
        } else {
            qWarning() << "AutoPilotPlugin::_recalcSetupComplete Incorrectly typed VehicleComponent";
        }
    }

    if (!_setupComplete) {
        qgcApp()->showAppMessage(tr("One or more vehicle components require setup prior to flight."));

        // Take the user to Vehicle Config Summary
        qgcApp()->showVehicleConfig();
        QCoreApplication::processEvents(QEventLoop::ExcludeUserInputEvents);
    }
}

VehicleComponent* AutoPilotPlugin::findKnownVehicleComponent(KnownVehicleComponent knownVehicleComponent)
{
    if (knownVehicleComponent != UnknownVehicleComponent) {
        for(const QVariant& componentVariant: vehicleComponents()) {
            VehicleComponent* component = qobject_cast<VehicleComponent*>(qvariant_cast<QObject *>(componentVariant));
            if (component && component->KnownVehicleComponent() == knownVehicleComponent) {
                return component;
            }
        }
    }

    return nullptr;
}
