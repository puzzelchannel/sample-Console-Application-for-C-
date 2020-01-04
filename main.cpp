#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct darss {
    string name;
    string family;
    string number;
    string clas;
};

bool sortByclas(const darss &a, const darss &b) { return a.clas < b.clas; }

class structor {
public:
    char input1, input2, input3;

    char menu1() {
        cout << "1- add" << "\t" << "2- print" << "\n" << "3-present" << endl;
        cin >> input1;
        return input1;
    }

    char menu2() {
        cout << "1- add" << "\t" << "2- return" << endl;
        cin >> input2;
        return input2;
    }

    char menu3() {
        cout << "1-choose" << "\n" << "2-return" << endl;
        cin >> input3;
        return input3;
    }

    bool str(vector<darss> dars, string str) {
        for (int i = 0; i < dars.size(); i++) {
            if (dars.at(i).clas == str) {
                return true;
            }
        }
        return false;
    }

    bool cheek(vector<darss> dars, string name, string family, string number, string clas) {
        for (int i = 0; i < dars.size(); i++) {
            if (dars.at(i).name == name && dars.at(i).family == family && dars.at(i).number == number &&
                dars.at(i).clas == clas) {
                return false;
            }
        }
        return true;
    }

    /* bool cheak(vector<string> darsName, string str) {
         for (int i = 0; i < darsName.size(); ++i) {
             if (darsName.at(i) == str.at(i)) {
                 return true;
             }
         }
         return false;
     }*/
};

bool k2(string str) {

    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            return false;
        }
    }
    return true;
}


int main() {
    structor mystructor;
    string family, clas, name, number;
    char input, input1, input3;
    vector<darss> dars;
    MAINLOOP:
    while (true) {
        input = mystructor.menu1();
        if (input == '1') {
            while (true) {
                while (true) {
                    while (true) {
                        cout << "enter the name : " << endl;
                        cin >> name;
                        if (!k2(name)) {
                            cout << "Please enter an string only!" << endl;
                            continue;
                        }
                        break;
                    }
                    while (true) {
                        cout << "enter the family : " << endl;
                        cin >> family;
                        if (!k2(family)) {
                            cout << "Please enter an string only!" << endl;
                            continue;
                        }
                        break;
                    }

                    while (true) {
                        cout << "enter the number : " << endl;
                        cin >> number;
                        if (k2(number)) {
                            cout << "Please enter an Integer only!" << endl;
                            continue;
                        }
                        break;
                    }
                    while (true) {
                        cout << "enter your class: " << endl;
                        cin >> clas;
                        if (!k2(clas)) {
                            cout << "Please enter an string only!" << endl;
                            continue;
                        }
                        break;
                    }
                    bool b = mystructor.cheek(dars, name, family, number, clas);
                    if (!b) {
                        cout << "please try again" << endl;
                        continue;
                    }
                    darss tmp;
                    tmp.name = name;
                    tmp.family = family;
                    tmp.number = number;
                    tmp.clas = clas;
                    dars.push_back(tmp);
                    sort(dars.begin(), dars.end(), sortByclas);
                    break;
                }
                input1 = mystructor.menu2();
                if (input1 == '1') {
                    continue;
                }
                if (input1 == '2') {
                    goto MAINLOOP;
                }
            }
        } else if (input == '2') {
            cout << "name" << "\t\t" << "family" << "\t\t" << "number" << "\t\t" << "class" << endl;
            cout << "-------  " << "\t" << "-------  " << "\t" << "-------" << "\t\t" << "-------" << endl;

            for (int i = 0; i < dars.size(); ++i) {
                cout << dars.at(i).name << "\t\t" << dars.at(i).family << "\t\t" << dars.at(i).number << "\t\t"
                     << dars.at(i).clas << endl;
            }
        } else if (input == '3') {
            cout << "\t" << "All Class" << endl;
            vector<string> darsNames;
            string prev;
            for (int j = 0; j < dars.size(); ++j) {
                if (j == 0) {
                    darsNames.push_back(dars.at(j).clas);
                    prev = darsNames.at(0);
                } else {
                    if (prev != dars.at(j).clas) {
                        darsNames.push_back(dars.at(j).clas);
                        prev = dars.at(j).clas;
                    }
                }
            }
            for (int k = 0; k < darsNames.size(); ++k) {
                cout << darsNames.at(k) << endl;
            }
            while (true) {
                input3 = mystructor.menu3();
                while (true) {
                    if (input3 == '1') {
                        while (true) {
                            while (true) {
                                cout << "which class do you want : " << endl;
                                cin >> clas;
                                bool a = mystructor.str(dars, clas);
                                if (!a) {
                                    cout << "this class is not available please try again !" << endl;
                                    continue;
                                }
                                break;
                            }

                            cout << "name" << "\t\t" << "family" << "\t\t" << "number" << endl;
                            cout << "-------  " << "\t" << "-------  " << "\t" << "-------" << endl;
                            for (int i = 0; i < dars.size(); ++i) {
                                if (dars.at(i).clas == clas) {

                                    cout << dars.at(i).name << "\t\t" << dars.at(i).family << "\t\t"
                                         << dars.at(i).number
                                         << "\t\t" << endl;


                                }
                            }
                            break;
                        }
                    } else if (input3 == '2') {
                        goto MAINLOOP;
                    }
                    break;
                }
                break;

            }
        }
        break;
    }
    return 0;
}