#pragma once

#include <iostream>
#include <ctime>
#include <limits>
#include "enums.h"

namespace td {

#define SENSOR_DISTANCE_MM 100 // in mm

    class TrainDetection {
    protected:
        int id;
        SensorSide side = SensorSide::NOSIDE;
        DetectionState state = DetectionState::C;

        time_t startTimestamp = 0;
        double speed = 0.0;
        double length = 0.0;

        void computeSpeed(time_t coverTimestamp);
        void computeLength(time_t departionTimestamp);

    public:
        TrainDetection(int id, SensorSide side, time_t timestamp) : id(id), side(side), startTimestamp(timestamp) {}
        bool step(SensorSide side, EdgeDirection dir, time_t timestamp);

        int getId() const;
        SensorSide getSide() const;
        DetectionState getState() const;
        double getSpeed() const;
        double getLength() const;

        friend std::ostream &operator<<(std::ostream &stream, const TrainDetection& td);
    };

};