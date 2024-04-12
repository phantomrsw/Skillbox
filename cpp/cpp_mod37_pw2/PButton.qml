import QtQuick 2.0
import QtGraphicalEffects 1.0
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4

Button {/*Custom button*/
    id:root
    /*Background style of button*/
    property color backgroundDefaultColor:"#ff8000"//"#4e5bf2"
    //property color backgroundPressedColor:Qt.darker(backgroundDefaultColor,1.2)
    property color backgroundPressedColor:Qt.lighter(backgroundDefaultColor,1.2)
    background: Rectangle{
        implicitWidth: 60
        implicitHeight: 30
        color: root.down ? root.backgroundPressedColor:root.backgroundDefaultColor
        radius:3
        layer.enabled: true
        layer.effect: DropShadow{
            transparentBorder: true
            color: root.down ? root.backgroundPressedColor:root.backgroundDefaultColor
            //samples:20
        }

    }

    palette.buttonText: root.down ? "lightgray":"black"
    font.pixelSize: 24
    font.bold: true

}
