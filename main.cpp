
//Model::Model model;
//Controller::Controller controller;

#include "main.h"

using namespace std;

//THIS IS GOING AWAY
int l = 3;
int f = 5;
int temp1[] = {4, 0,1};
vector<int> LIFTPASSENGERS(temp1, temp1+3);
int temp03[] = {3, 1,0};
vector<int> NEWLIFTPASSENGERS(temp03, temp03+3);
int temp2[] = {0, 0, 3};
vector<int> LIFTSTARTFLOOR(temp2, temp2+3);
int temp01[] = {1, 1, 2};
vector<int> LIFTFLOOR(temp01, temp01+3);
int temp3[] = {0, 1, -1};
vector<int> LIFTSTARTDIR(temp3, temp3+3);
int temp02[] = {1, 1, -1};
vector<int> LIFTDIR(temp02, temp02+3);
int temp4[] = {3, 0, 0, 2, 1};
vector<int> FLOORPASSENGERS(temp4, temp4+5);
int temp04[] = {4, 1, 1, 0, 0};
vector<int> NEWFLOORPASSENGERS(temp04, temp04+5);
bool temp5[] = {0, 0, 0, 1, 0};
bool temp6[] = {1, 1, 0, 0, 0};
bool temp7[] = {1, 1, 1, 1, 1};
vector<bool> t5(temp5, temp5+5);
vector<bool> t6(temp6, temp6+5);
vector<bool> t7(temp7, temp7+5);
vector<bool> temp8[] = {t5, t6, t7};
vector< vector<bool> > LIFTBUTTONS(temp8, temp8+3);
bool temp05[] = {1, 1, 0, 1, 0};
bool temp06[] = {0, 0, 0, 0, 0};
bool temp07[] = {1, 0, 1, 1, 1};
vector<bool> t05(temp05, temp05+5);
vector<bool> t06(temp06, temp06+5);
vector<bool> t07(temp07, temp07+5);
vector<bool> temp08[] = {t05, t06, t07};
vector< vector<bool> > NEWLIFTBUTTONS(temp08, temp08+3);
bool temp9[] = {1, 0};
bool temp10[] = {1, 1};
bool temp11[] = {1, 1};
bool temp12[] = {1, 1};
bool temp13[] = {0, 1};
vector<bool> t9(temp9, temp9+1);
vector<bool> t10(temp10, temp10+2);
vector<bool> t11(temp11, temp11+2);
vector<bool> t12(temp12, temp12+2);
vector<bool> t13(temp13, temp13+2);
vector<bool> temp14[] = {t9, t10, t11, t12, t13};
vector< vector<bool> > FLOORBUTTONS(temp14, temp14+5);
bool temp09[] = {0, 0};
bool temp010[] = {0, 1};
bool temp011[] = {0, 1};
bool temp012[] = {0, 1};
bool temp013[] = {0, 0};
vector<bool> t09(temp09, temp09+1);
vector<bool> t010(temp010, temp010+2);
vector<bool> t011(temp011, temp011+2);
vector<bool> t012(temp012, temp012+2);
vector<bool> t013(temp013, temp013+2);
vector<bool> temp014[] = {t09, t010, t011, t012, t013};
vector< vector<bool> > NEWFLOORBUTTONS(temp014, temp014+5);

View initialiseView() {
    //model provides information which is set to these spots
    View::View v(f, l, LIFTPASSENGERS, LIFTSTARTFLOOR, LIFTSTARTDIR, FLOORPASSENGERS, LIFTBUTTONS, FLOORBUTTONS);
    return v;
}

int main() {
	//Model m("file.csv");
	//Controller c(&m);
    View view = initialiseView();
    view.create();
	Clock cl;
	int i = 0;
    while (true) {
		if (cl.nextTick()) {
			i = cl.getCounter();
            cout << i << "\n";
            view.update(NEWLIFTPASSENGERS, LIFTFLOOR, LIFTDIR, NEWFLOORPASSENGERS, NEWLIFTBUTTONS, NEWFLOORBUTTONS);
        }
	}
    return 0;

}

