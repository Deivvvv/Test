
import QtQuick 2.0
import QtMultimedia 5.0
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2
import QtQuick.Layouts 1.1
import QtQuick.Dialogs 1.2
import QtQuick.Window 2.2


Window{
    id:myPlayer
    width: 640
    height: 480
    visible: true
    title: qsTr("MyPlayer:");

    Text{
    text: "This player"
    font.pointSize: 24
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.verticalCenter: parent.verticalCenter
    }

    Button {
    text: " ▶️ "
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.verticalCenter: parent.verticalCenter
    anchors.verticalCenterOffset: 200
    anchors.horizontalCenterOffset: -50
    }

    Button {
    text: " ⏸️ "
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.verticalCenter: parent.verticalCenter
    anchors.verticalCenterOffset: 200
    anchors.horizontalCenterOffset: -30
    }

    Button {
        text: " ⏹ "
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 200
        anchors.horizontalCenterOffset: -10
        }

    Button {
    text: " ⏪️ "
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.verticalCenter: parent.verticalCenter
    anchors.verticalCenterOffset: 200
    anchors.horizontalCenterOffset: 10
    }

    Button {
    text: " ⏩️ "
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.verticalCenter: parent.verticalCenter
    anchors.verticalCenterOffset: 200
    anchors.horizontalCenterOffset: 30
    }

    ProgressBar {
        value: 0.5
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 200
    }
}

