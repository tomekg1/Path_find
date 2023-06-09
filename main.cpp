#include <vector>
#include "planche.hpp"

int main()
{
    std::vector<std::vector<char>> planche1 {{'#', '#', '#', '#', '#', ' ', '#'},
                                             {'#', '#', ' ', ' ', ' ', ' ', '#'},
                                             {'#', ' ', ' ', '#', '#', ' ', '#'},
                                             {' ', ' ', '#', '#', '#', ' ', ' '},
                                             {' ', '#', ' ', ' ', ' ', '#', ' '},
                                             {'#', '#', ' ', '#', ' ', ' ', ' '},
                                             {'#', '#', ' ', '#', '#', '#', '#'}};

    Planche P1(planche1);
    P1.print_points();
    P1.dfs_iter();

}
