#include "HeatpointModel.h"

HeatpointModel::HeatpointModel(QObject* parent) : QAbstractListModel(parent) {}

void HeatpointModel::updateHeatpoints(const QList<MAVLinkProtocol::Heatpoint>& heatpoints) {
    beginResetModel();
    m_heatpoints = heatpoints;
    endResetModel();
}

int HeatpointModel::rowCount(const QModelIndex& parent) const {
    Q_UNUSED(parent);
    return m_heatpoints.size();
}

QVariant HeatpointModel::data(const QModelIndex& index, int role) const {
    if (!index.isValid() || index.row() >= m_heatpoints.size()) {
        return QVariant();
    }

    const MAVLinkProtocol::Heatpoint& point = m_heatpoints[index.row()];
    switch (role) {
        case LatRole: return point.lat;
        case LonRole: return point.lon;
        case IntensityRole: return point.color_intensity;
        default: return QVariant();
    }
}

QHash<int, QByteArray> HeatpointModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[LatRole] = "lat";
    roles[LonRole] = "lon";
    roles[IntensityRole] = "intensity";
    return roles;
}
