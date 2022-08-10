#ifndef UTILS_H_
#define UTILS_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sys/types.h>    
#include <sys/stat.h>
#include <functional>
#include <map>
#include <limits.h>
#include <memory>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <Eigen/Core>
#include <Eigen/StdVector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/eigen.hpp>

#include <g2o/types/slam3d/types_slam3d.h>
#include <g2o/types/slam3d_addons/types_slam3d_addons.h>

typedef std::shared_ptr<g2o::Line3D> Line3DPtr;
typedef std::shared_ptr<const g2o::Line3D> ConstLine3DPtr;

// Eigen type
typedef Eigen::Matrix<double, 6, 1> Vector6d;

template <template <typename, typename> class Container, typename Type>
using Aligned = Container<Type, Eigen::aligned_allocator<Type>>;

template <typename KeyType, typename ValueType>
using AlignedMap =
    std::map<KeyType, ValueType, std::less<KeyType>,
             Eigen::aligned_allocator<std::pair<const KeyType, ValueType>>>;

template <typename KeyType, typename ValueType>
using AlignedUnorderedMap = std::unordered_map<
    KeyType, ValueType, std::hash<KeyType>, std::equal_to<KeyType>,
    Eigen::aligned_allocator<std::pair<const KeyType, ValueType>>>;

template <typename KeyType, typename ValueType>
using AlignedUnorderedMultimap = std::unordered_multimap<
    KeyType, ValueType, std::hash<KeyType>, std::equal_to<KeyType>,
    Eigen::aligned_allocator<std::pair<const KeyType, ValueType>>>;

template <typename Type>
using AlignedUnorderedSet =
    std::unordered_set<Type, std::hash<Type>, std::equal_to<Type>,
                       Eigen::aligned_allocator<Type>>;

void ConvertVectorToRt(Eigen::Matrix<double, 7, 1>& m, Eigen::Matrix3d& R, Eigen::Vector3d& t);
double DescriptorDistance(const Eigen::Matrix<double, 256, 1>& f1, const Eigen::Matrix<double, 256, 1>& f2);
cv::Scalar GenerateColor(int id);
void GenerateColor(int id, Eigen::Vector3d color);

// files
void GetFileNames(std::string path, std::vector<std::string>& filenames);
bool FileExists(const std::string& file);
bool PathExists(const std::string& path);
void ConcatenateFolderAndFileName(
    const std::string& folder, const std::string& file_name,
    std::string* path);

std::string ConcatenateFolderAndFileName(
    const std::string& folder, const std::string& file_name);

void MakeDir(const std::string& path);

void ReadTxt(const std::string& file_path, 
    std::vector<std::vector<std::string> >& lines, std::string seq);

void WriteTxt(const std::string file_path, 
    std::vector<std::vector<std::string> >& lines, std::string seq);

#endif  // UTILS_H_