#pragma once

#include <map>
#include <optional>
#include <string>

#include <eigen3/Eigen/Dense>

struct LoopRelativePose
{
    Eigen::Vector3d translation = Eigen::Vector3d::Zero();
    Eigen::Quaterniond rotation = Eigen::Quaterniond::Identity();
    double yaw_degrees = 0.0;
};

struct LoopProposal
{
    enum class Status
    {
        Rejected,
        Accepted
    };

    int target_keyframe_index = -1;
    int rank = -1;
    double confidence = 0.0;
    std::optional<LoopRelativePose> relative_pose;
    Status status = Status::Rejected;
    std::string reject_reason;
    std::string method_name;
    std::map<std::string, double> metrics;

    bool accepted() const
    {
        return status == Status::Accepted;
    }
};
