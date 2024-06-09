import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: root
    width: 800
    height: 300
    visible: true
    title: qsTr("Click ball")
    Rectangle{
        id:scene
        anchors.fill: parent
        state: "LeftState"

        Rectangle{
            id:leftRectangle
            x:100
            y:100
            color:"lightgray"
            width:100
            height:100
            border.color: "black"
            border.width: 3
            radius: 5
            Text{
                id:lrText
                anchors.centerIn: parent
                text: "move"
                font.pointSize: 16
            }
            MouseArea{
                anchors.fill:parent
                onClicked:{
                    ball.x += 30
                    if(ball.x >= rightRectangle.x - rightRectangle.width/2 - ball.width/2)
                        scene.state = "InitialState"
                    else{
                        scene.state = "OtherState"
                    }
                }
                onPressed: {
                    lrText.font.pointSize = 15
                    leftRectangle.border.width = 5
                    leftRectangle.color = "darkgray"
                }
                onReleased: {
                    lrText.font.pointSize = 16
                    leftRectangle.border.width = 3
                    leftRectangle.color = "lightgray"
                }
            }
        }

        Rectangle{
            id:rightRectangle
            x:600
            y:100
            color:"lightgray"
            width:100
            height:100
            border.color: "black"
            border.width: 3
            radius: 5
            Text{
                id:rrText
                anchors.centerIn: parent
                text: "return"
                font.pointSize: 16
            }
            MouseArea{
                anchors.fill:parent
                onClicked: scene.state = "InitialState"
                onPressed: {
                    rrText.font.pointSize = 15
                    rightRectangle.border.width = 5
                    rightRectangle.color = "darkgray"
                }
                onReleased: {
                    rrText.font.pointSize = 16
                    rightRectangle.border.width = 3
                    rightRectangle.color = "lightgray"
                }
            }
        }

        Rectangle{
            id:ball
            color:"darkgreen"
            x:leftRectangle.x + leftRectangle.width + 5
            y:leftRectangle.y + 5
            width: leftRectangle.width - 10
            height: leftRectangle.height - 10
            radius: width / 2
        }

        states:[
            State{
                name:"InitialState"
                PropertyChanges {
                    target: ball
                    x:leftRectangle.x + leftRectangle.width + 5
                }
            },
            State {
               name: "OtherState"
               PropertyChanges {
                   target: ball
                   x: ball.x
               }
            }
        ]//end states

        transitions: [
            Transition {
               from: "OtherState"
               to: "InitialState"
               NumberAnimation {
                   properties: "x,y"
                   duration: 1000
                   easing.type: Easing.OutBounce
               }
            }
        ]//end transitions
    }
}
