class Ponto {
  private:
    double _x;
    double _y;

  public:
    Ponto(double x, double y) {
      _x = x;
      _y = y;
    }
};

int main() {
  Ponto p = Ponto(2.0, 3.0);
  return 0;
}