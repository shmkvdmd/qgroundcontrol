import QtQuick
import QtLocation
import QtPositioning

MapQuickItem {
    id: heatpointItem
    Component.onCompleted: console.log("Heatpoint: lat=" + lat + ", lon=" + lon + ", intensity=" + intensity)
    anchorPoint: Qt.point(sourceItem.width / 2, sourceItem.height / 2)

    sourceItem: Rectangle {
        width: 20
        height: 20
        radius: 10
        opacity: 0.7
        color: {
            var i = intensity / 10.0;
            var r = i;
            var g = 1 - i;
            return Qt.rgba(r, g, 0, 1);
        }
        border.width: 1
        border.color: "black"
    }

    coordinate: QtPositioning.coordinate(lat, lon)

    property real lat: 0
    property real lon: 0
    property real intensity: 0
}
