#include <iostream>
#include <string>
#include <vector>
 
enum lol {
    Isotype,
    Radioactive,
    Ion,
    Antimatter,
    Stable,
};
 
class Atom
{
public:
    std::string name;
    int atomic_mass_unit;
    int protons_number;
    int electrons_number;
    lol type;
    bool IsNeutral();
 
Atom() {
    name = "Hydrogen";
    atomic_mass_unit = 1;
    protons_number = 1;
    electrons_number = 1;
    lol type = Stable;
}
 
Atom(std::string a, int b, int c, int d, lol e) {
    name = a;
    atomic_mass_unit = b;
    protons_number = c;
    electrons_number = d;
    type = e;
}
 
};
 
bool Atom::IsNeutral() {
    if (Atom::protons_number == Atom::electrons_number) {
        return true;
    } else {
        return false;
    }
}
 
 
 
 
class Molecule
{
public:
  friend Atom;
 
  std::string name;
  std::vector<Atom> Atoms;
  void SortAtoms();
  float FindAverageMass();
 
Molecule() {
  name = "Aqua";
  std::string n = "Oxygen";
  Atom H1, H2, O1{ n, 16, 8, 8, Stable };
  Atoms.push_back(H1);
  Atoms.push_back(H2);
  Atoms.push_back(O1);
}

Molecule(std::string a, std::vector<Atom> b) {
    name = a;
    Atoms = b;
}
 
};

float Molecule::FindAverageMass(){
	int sum = 0;
	for (int i = 0; i < Atoms.size(); i++)
		sum = sum + Atoms[i].atomic_mass_unit;
	return sum/Atoms.size();
}

void Molecule::SortAtoms(){
int n = Atoms.size();

for (int j=0; j<n; j++){
int nmin=j;

	for (int k=j+1; k<n; k++)
	if(Atoms[k].atomic_mass_unit<Atoms[nmin].atomic_mass_unit) nmin=k;
	Atom p = Atoms[j];
	Atoms[j] = Atoms[nmin];
	Atoms[nmin] = p;

}
	
}
 
int main(){
 	
	Molecule M;
	M.SortAtoms();
	
	for (int i = 1; i <= M.Atoms.size(); i++) {
        std::cout << "Назва: " << M.Atoms[i].name << std::endl;
        std::cout << "Порядковий номер: " << i << std::endl;
        std::cout << "Маса: " << M.Atoms[i].atomic_mass_unit << std::endl;
	}
	
	return 0; 

}