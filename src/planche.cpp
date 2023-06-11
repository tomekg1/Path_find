#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <algorithm>
#include "planche.hpp"


void Planche::create_points() {
    for(std::size_t i=0; i<planche_.size(); i++){
        const std::vector<char>& row = planche_[i];
        for(std::size_t j=0; j<row.size(); j++){
            const char& elem = row[j];
            if(elem == ' '){
                Point p = {i, j};
                points_.push_back(p);

            }
        }
    }
}

void Planche::create_adj_list() {
    create_points();

    for(auto& p : points_) {
        std::vector<Point> neighbours;
        for (auto& n : points_) {
            if ((n.x != p.x) || (n.y != p.y)) {
                if (((p.x == n.x) && ((p.y == n.y + 1) || (p.y == n.y - 1))) ||
                    ((p.y == n.y) && ((p.x == n.x + 1) || (p.x == n.x - 1)))) {
                    neighbours.push_back(n);
                }
            }
        }
        for (std::size_t i = 0; i < neighbours.size() - 1; i++) {
            for (std::size_t j = 0; j < neighbours.size() - i - 1; j++) {
                if (neighbours[j].y > neighbours[j + 1].y) {
                    std::swap(neighbours[j], neighbours[j + 1]);

                }
            }
        }
        adj_list_.emplace(p, neighbours);

    }
}

void Planche::show_planche() const{
    for (const auto& row : planche_) {
        for (const auto& ch : row) {
            std::cout << ch << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}


void Planche::update_planche(Point v) {
    planche_[v.x][v.y] = '+';
    show_planche();
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
}

std::vector<Point> Planche::dfs_iter() {
    std::vector<Point> stack;
    std::vector<Point> path;
    stack.push_back(points_[0]);

    while(!stack.empty()){
        Point v = stack.back();
        stack.pop_back();

        auto it = std::find(path.begin(), path.end(), v);
        if(it != path.end()){
            continue;
        }
        else{
            path.push_back(v);
            update_planche(v);
            if(v.x == planche_.size() - 1){
                std::cout<< "-------- PATH FOUND --------" << std::endl;
                return path;
            }
            std::reverse(adj_list_[v].begin(), adj_list_[v].end());
            for(const auto& i : adj_list_[v]){
                stack.push_back(i);
            }
        }
    }
    return path;
}



void Planche::print_points() const{
    for (const auto& pair : adj_list_) {
        const Point& key = pair.first;
        const std::vector<Point>& value = pair.second;

        std::cout << "Key: (" << key.x << ", " << key.y << ")" << std::endl;

        std::cout << "Value: ";
        for (const Point& point : value) {
            std::cout << "(" << point.x << ", " << point.y << ") ";
        }
        std::cout << std::endl;
    }
}