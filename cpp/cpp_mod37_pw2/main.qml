import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3
import QtMultimedia 5.12

/*Add custom style buttom */
import "."

Window {
    width: 640
    height: 480
    minimumWidth: row_layout_btn.width + row_layout_volume_slider.width
    minimumHeight: 240
    visible: true
    title: qsTr("Video Player")

    property color backColor:"#999999" //"#666666"
    color: backColor

    MenuBar {
        id:menu_bar
        anchors.left: parent.left
        anchors.right: parent.right
        palette.window: backColor
        Menu {
            title: qsTr("&Media")
            Action { text: qsTr("&Open file...") }
            Action { text: qsTr("&Open folder...") }
            MenuSeparator { }
            Action { text: qsTr("&Exit") }
        }
        Menu {
            title: qsTr("&Play")
            Action { text: qsTr("\u25ba &Play") }
            Action { text: qsTr("\u2016 &Pause") }
            Action { text: qsTr("\u25a0 &Stop") }
            Action { text: qsTr("<< &Rewind") }
            Action { text: qsTr(">> &Forward") }
        }
        Menu {
            title: qsTr("&Help")
            Action { text: qsTr("&About") }
        }

        background: Rectangle {
                implicitHeight: 20
                color: backColor
            }
    }

    property string mediaSource: "file://Video1.mp4"
    //property string mediaSource: "file://Jingle bell.wav"

    Rectangle {
        color:"black"

        anchors.top: menu_bar.bottom
        anchors.bottom: row_layout_control.top
        anchors.left: parent.left
        anchors.right: parent.right

        MediaPlayer {
            id: mediaplayer
            source: mediaSource
        }

        VideoOutput {
            id:videoOutput
            anchors.fill: parent
            source: mediaplayer
        }
    }


    RowLayout {
        id : row_layout_control
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: row_layout_progress.top

        RowLayout{
            id : row_layout_btn
            anchors.left: parent.left

            PButton {/*Play*/
                id:btn_play
                text: "\u25ba"
                onClicked: {
                    mediaplayer.play();
                    console.log("Error=",mediaplayer.errorString)
                    console.log("PLAY button clicked")
                }
            }

            PButton {/*Pause*/
                id:btn_pause
                text: "\u2016"
                onClicked:{
                    console.log("PAUSE button clicked")
                }
            }

            PButton {/*Stop*/
                id:btn_stop
                text:"\u25a0"
                onClicked:{
                    mediaplayer.stop()
                    console.log("STOP button clicked")
                }
            }

            PButton {/*Rewind*/
                id:btn_rewind
                text: "<<"
                onClicked:{
                    console.log("REWIND button clicked")
                }
            }

            PButton {/*Forward*/
                id:btn_forward
                text: ">>"
                onClicked:{
                    console.log("FORWARD button clicked")
                }
            }

        }

        RowLayout{
            id : row_layout_volume_slider
            anchors.right: parent.right
            Slider{
                value:0.5
                from:0
                to : 1.0
                stepSize: 0.01
                palette.window: "#ff8000"
            }
        }

    }

    RowLayout{
        id : row_layout_progress
        width : parent.width
        anchors.bottom: parent.bottom

        Slider{
            value:0.8
            from:0
            to : 1.0
            stepSize: 0.01
            palette.window: "#ff8000"

            anchors.right: parent.right
            anchors.left: parent.left

            onMoved: {
                console.log("SLIDER moved val=",value)
            }
        }
    }

}

