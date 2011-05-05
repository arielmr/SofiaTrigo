import Qt 4.7
Item {
    id:tabControl
    width: 132
    height:523
    clip: true
    signal teoria()
    signal ejercicios()
    signal graficar()
    MouseArea {
        id: mouse_area1
        x: 9
        y: 45
        width: 100
        height: 100
        onClicked:{
            parent.state = ""
            tabControl.teoria()
        }
    }

    MouseArea {
        id: mouse_area2
        x: 9
        y: 212
        width: 100
        height: 100
        onClicked: {
            parent.state = "State1"
            tabControl.ejercicios()
        }
    }

    MouseArea {
        id: mouse_area3
        x: 9
        y: 377
        width: 100
        height: 100
        onClicked: {
            parent.state = "State2"
            tabControl.graficar()
        }
    }
    Image {
        id: subtab3
        source: "images/subtab3.png"
        x: 0
        y: 0
        opacity: 1
    }
    Image {
        id: hugetab
        source: "images/hugetab.png"
        x: 4
        y: 7
        opacity: 1
        Behavior on y {
            NumberAnimation{
                duration: 400
                easing.type: Easing.OutExpo
            }
        }
    }
    Image {
        id: maintab3
        source: "images/maintab3.png"
        x: 4
        y: 0
        opacity: 1
    }
    Text {
        id: graficar
        text: "GRAFICAR"
        font.pixelSize: 12
        font.family: "ArialMT"
        color: "#ffffff"
        smooth: true
        x: 20
        y: 383.750000715256
        opacity: 1
    }
    Text {
        id: ejercicios
        text: "EJERCICIOS"
        font.pixelSize: 12
        font.family: "ArialMT"
        color: "#ffffff"
        smooth: true
        x: 21
        y: 219.750000715256
        opacity: 1
    }
    Text {
        id: teoria
        text: "TEORIA"
        font.pixelSize: 12
        font.family: "ArialMT"
        color: "#ffffff"
        smooth: true
        x: 33
        y: 46.7500007152557
        opacity: 1
    }
    states: [
        State {
            name: "State1"
            PropertyChanges {
                target: hugetab
                x: 4
                y: 171
            }
        },
        State {
            name: "State2"
            PropertyChanges {
                target: hugetab
                x: 4
                y: 339
            }
        }
    ]
}
