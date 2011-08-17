# Copyright (c) 2011 Dmitry Suvorov <D.Suvorov90@gmail.com>

define robot position
(
    # actual size
    size [ 0.415 0.3 0.483 ]
    # centre of rotation offset
    origin [ 0 0 0 90 ]

    # positonal things
    drive "diff"

    # the shape of the robot
    block
    (
        points 8
        point[7] [ -0.166 -0.152 ]
        point[6] [ 0.168 -0.152 ]
        point[5] [ 0.208 -0.11 ]
        point[4] [ 0.208 0.066 ]
        point[3] [ 0.126 0.146 ]
        point[2] [ -0.126 0.146 ]
        point[1] [ -0.208 0.066 ]
        point[0] [ -0.208 -0.11 ]

        z [ 0 0.047 ]

	color "gray"
    )
    block
    (
        points 8
        point[7] [ -0.166 -0.152 ]
        point[6] [ 0.168 -0.152 ]
        point[5] [ 0.187 -0.132 ]
        point[4] [ 0.187 0.085 ]
        point[3] [ 0.126 0.146 ]
        point[2] [ -0.126 0.146 ]
        point[1] [ -0.188 0.085 ]
        point[0] [ -0.188 -0.132 ]

        z [ 0.047 0.098 ]

	color "gray"
    )
    block
    (
        points 6
        point[5] [ -0.188 -0.112 ]
        point[4] [ 0.187 -0.112 ]
        point[3] [ 0.187 0.085 ]
        point[2] [ 0.126 0.146 ]
        point[1] [ -0.126 0.146 ]
        point[0] [ -0.188 0.085 ]

        z [ 0.098 0.387 ]

	color "gray"
    )
    block
    (
        points 4
        point[3] [ -0.04 -0.04 ]
        point[2] [ 0.04 -0.04 ]
        point[1] [ 0.04 0.04 ]
        point[0] [ -0.04 0.04 ]

        z [ 0.387 0.483 ]

	color "white"
    )

    mass 5

    gui_move 0
)
