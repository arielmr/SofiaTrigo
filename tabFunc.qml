import Qt 4.7
Item {
    id: tabFunctions
    width:132
    height:523
    clip: true
    signal selectFunction(string func)
    Image {
        id: backtab
        z: -5
        source: "images/backtab.png"
        opacity: 1
    }
    Image {
        id: slider
        clip: true
        source: "images/slider.png"
        opacity: 1
        Behavior on y {
            NumberAnimation{
                duration: 400
                easing.type: Easing.OutExpo
            }
        }
    }
    Image {
        id: maintab
        source: "images/maintab.png"
        opacity: 1
    }
    MouseArea {
        id: mouse_area1
        x: 13
        y: 38
        width: 110
        height: 52
        onClicked: {
            tabFunctions.selectFunction("sin")
            parent.state = ""
        }
    }
    MouseArea {
        id: mouse_area2
        x: 13
        y: 94
        width: 110
        height: 52
        onClicked: {
            tabFunctions.selectFunction("cos")
            parent.state = "State1"
        }
    }
    MouseArea {
        id: mouse_area3
        x: 13
        y: 151
        width: 110
        height: 52
        onClicked: {
            tabFunctions.selectFunction("tan")
            parent.state = "State2"
        }
    }
    MouseArea {
        id: mouse_area4
        x: 13
        y: 207
        width: 110
        height: 52
        onClicked: {
            tabFunctions.selectFunction("cot")
            parent.state = "State3"
        }
    }
    MouseArea {
        id: mouse_area5
        x: 13
        y: 264
        width: 110
        height: 52
        onClicked: {
            tabFunctions.selectFunction("sec")
            parent.state = "State4"
        }
    }
    MouseArea {
        id: mouse_area6
        x: 13
        y: 321
        width: 110
        height: 52
        onClicked: {
            tabFunctions.selectFunction("csc")
            parent.state = "State5"
        }
    }
    Image {
        id: seno
        source: "images/seno.png"
        opacity: 1      
    }
    Image {
        id: coseno
        source: "images/coseno.png"
        opacity: 1       
    }
    Image {
        id: tangente
        source: "images/tangente.png"
        opacity: 1
    }
    Image {
        id: secante_
        source: "images/secante_.png"
        opacity: 1
    }
    Image {
        id: cosecante
        source: "images/cosecante.png"
        opacity: 1
    }
    Image {
        id: cotangente
        smooth: true
        fillMode: Image.PreserveAspectFit
        source: "images/cotangente.png"
        opacity: 1
    }
    states: [
        State {
            name: "State1"

            PropertyChanges {
                target: slider
                x: 0
                y: 59
            }
        },
        State {
            name: "State2"
            PropertyChanges {
                target: slider
                x: 0
                y: 113
            }
        },
        State {
            name: "State3"
            PropertyChanges {
                target: slider
                x: 0
                y: 169
            }
        },
        State {
            name: "State4"
            PropertyChanges {
                target: slider
                x: 0
                y: 226
            }
        },
        State {
            name: "State5"
            PropertyChanges {
                target: slider
                x: 0
                y: 283
                height: 522
            }
        }
    ]


}
