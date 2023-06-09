#include <iostream>
#include <vector>
#include <map>

#ifndef DFS_VIS_CPP_PLANCHE_HPP
#define DFS_VIS_CPP_PLANCHE_HPP

#endif //DFS_VIS_CPP_PLANCHE_HPP

struct Point{
    uint32_t x;
    uint32_t y;

    bool operator<(const Point& other) const { // potrzebna obsługa operatora < do wykonania: adj_list_.emplace(p, neighbours);
        if (x < other.x) {
            return true;
        } else if (x == other.x) {
            return y < other.y;
        }
        return false;
    }

    bool operator==(const Point& other) const{ // potrzebne do std::reverse
        if ((x == other.x) && (y == other.y)){
            return true;
        }
        else{
            return false;
        }
    }
};


class Planche{
public:
    Planche(std::vector<std::vector<char>> planche): planche_(planche) {
        create_adj_list();
    }

    void print_points();
    std::vector<Point> dfs_iter();

private:
    std::vector<std::vector<char>> planche_;
    std::vector<Point> points_;
    std::map<Point, std::vector<Point>> adj_list_;

    void create_points();
    void create_adj_list();
    void show_planche();
    void update_planche(Point v);
};
