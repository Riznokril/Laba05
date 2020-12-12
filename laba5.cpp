#include <iostream>
#include <string>
#include <vector>
 
enum original_type {
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
    original_type type;
    bool IsNeutral();
 
Atom() {
    name = "Hydrogen";
    atomic_mass_unit = 1;
    protons_number = 1;
    electrons_number = 1;
    type = Stable;
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
    if (protons_number == electrons_number) {
        return true;
    } else {
        return false;
    }
}
 
 
 
 
class Molecule
{
public:
 
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
    int length_of_vector = Atoms.size();
	for (int i = 0; i < length_of_vector; i++)
		sum = sum + Atoms[i].atomic_mass_unit;
	return sum / length_of_vector();
}

void Molecule::SortAtoms(){
int length_of_vector = Atoms.size();

for (int j = 0; j < length_of_vector; j++){
int current_number_of_sorting=j;

	for (int current_number = j+1; current_number < length_of_vector; current_number++)
	if(Atoms[current_number].atomic_mass_unit<Atoms[current_number_of_sorting].atomic_mass_unit)
        current_number_of_sorting=current_number;
	Atom p = Atoms[j];
	Atoms[j] = Atoms[current_number_of_sorting];
	Atoms[current_number_of_sorting] = p;

}
	
}
 
int main(){
 	
	Molecule M;
	M.SortAtoms();
	
	for (int i = 0; i <= M.Atoms.size(); i++) {
        std::cout << "Назва: " << M.Atoms[i].name << std::endl;
        std::cout << "Порядковий номер: " << i << std::endl;
        std::cout << "Маса: " << M.Atoms[i].atomic_mass_unit << std::endl;
	}
	
	return 0; 

}