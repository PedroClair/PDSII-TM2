#include "../include/ponto.hpp"

Ponto::Ponto (double x, double y){
    _x = x;
    _y = y;
}

double Ponto::get_x(){
    return _x;
}

double Ponto::get_y(){
    return _y;
}