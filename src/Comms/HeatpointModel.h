#ifndef HEATPOINTMODEL_H
#define HEATPOINTMODEL_H

#include <QAbstractListModel>
#include <QList>
#include "MAVLinkProtocol.h"

class HeatpointModel : public QAbstractListModel {
    Q_OBJECT
   public:
    explicit HeatpointModel(QObject* parent = nullptr);

    enum HeatpointRoles {
        LatRole = Qt::UserRole + 1,
        LonRole,
        IntensityRole
    };

    void updateHeatpoints(const QList<MAVLinkProtocol::Heatpoint>& heatpoints);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

   private:
    QList<MAVLinkProtocol::Heatpoint> m_heatpoints;
};

#endif // HEATPOINTMODEL_H
