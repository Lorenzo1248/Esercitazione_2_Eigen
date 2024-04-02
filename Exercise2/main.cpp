#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main() {

    //Definisco le matrici A e b per ogni sistema
    Matrix2d A1, A2, A3;
    Vector2d b1, b2, b3;

    A1 << 5.547001962252291e-01, -3.770900990025203e-02, 8.320502943378437e-01, -9.992887623566787e-01;
    b1 << -5.169911863249772e-01, 1.672384680188350e-01;

    A2 << 5.547001962252291e-01, -5.540607316466765e-01, 8.320502943378437e-01, -8.324762492991313e-01;
    b2 << -6.394645785530173e-04, 4.259549612877223e-04;

    A3 << 5.547001962252291e-01, -5.547001955851905e-01, 8.320502943378437e-01, -8.320502947645361e-01;
    b3 << -6.400391328043042e-10, 4.266924591433963e-10;

    //Soluzione con decomposizione PALU
    //Vector2d x1, x2, x3;(posso anche chiamarlo una sola volta per tutto l'esercizio)
    Vector2d x1_PALU = A1.partialPivLu().solve(b1);
    Vector2d x2_PALU = A2.partialPivLu().solve(b2);
    Vector2d x3_PALU = A3.partialPivLu().solve(b3);

    //Calcolo gli errori relativi
    double errore_rel1 = (A1 * x1_PALU - b1).norm() / b1.norm();
    double errore_rel2 = (A2 * x2_PALU - b2).norm() / b2.norm();
    double errore_rel3 = (A3 * x3_PALU - b3).norm() / b3.norm();

    cout << "Errori relativi con la decomposizione PALU:" << endl;
    cout << "Sistema 1: " << errore_rel1 << endl;
    cout << "Sistema 2: " << errore_rel2 << endl;
    cout << "Sistema 3: " << errore_rel3 << endl;

    //Soluzione con decomposizione QR
    Vector2d x1_QR = A1.colPivHouseholderQr().solve(b1);
    Vector2d x2_QR = A2.colPivHouseholderQr().solve(b2);
    Vector2d x3_QR = A3.colPivHouseholderQr().solve(b3);

    //Calcolo gli errori relativi
    errore_rel1 = (A1 * x1_QR - b1).norm() / b1.norm();
    errore_rel2 = (A2 * x2_QR - b2).norm() / b2.norm();
    errore_rel3 = (A3 * x3_QR - b3).norm() / b3.norm();

    cout << "Errori relativi con la decomposizione QR:" << endl;
    cout << "Sistema 1: " << errore_rel1 << endl;
    cout << "Sistema 2: " << errore_rel2 << endl;
    cout << "Sistema 3: " << errore_rel3 << endl;

    return 0;
}

