#include "HashTable.h"

void mainMenu()
{
    cout << "\nChoose action: \n";
    cout << "\t1. Add term\n";
    cout << "\t2. Remove term\n";
    cout << "\t3. Find term\n";
    cout << "\t4. Show table\n";
    cout << "\t5. Exit\n";
    cout << "Your action: ";
}

int main()
{
    string term, definition;
    HashTable ht;
    ht.addTermin("Abscissa", "one of the Cartesian coordinates of a point, usually the first, denoted by the letter.");
    ht.addTermin("Diameter", "the chord passing through its(its) centre; length is equal to twice the radius.");
    ht.addTermin("Lemma", "an auxiliary proposition that is a true statement used in proving other statements (theorems).");
    ht.addTermin("Mathematics", "the science of quantitative relations and spatial forms of the actual world.");
    ht.addTermin("Stereometry", "a part of elementary geometry that studies the properties of figures arranged in space.");
    ht.addTermin("Ordinate", "one of the Cartesian coordinates of a point, usually the second, denoted by the letter y.");
    ht.addTermin("Mantissa", "the fractional part of the decimal logarithm of a positive number.");
    ht.addTermin("Vertical angles", "pairs of angles with a common vertex formed by the intersection of two straight lines such that the sides of one angle are extensions of the sides of the other.");
    ht.addTermin("Set", "a aggregate, collection of any objects, called its elements, having a characteristic property common to them.");
    ht.addTermin("Abscissa", "one of the Cartesian coordinates of a point, usually the first, denoted by the letter.");
    ht.addTermin("Abscissa", "one of the Cartesian coordinates of a point, usually the first, denoted by the letter.");
    bool start = true;
    int indexFind;
    while (start)
    {
        int choice;
        mainMenu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter term to add: ";
            cin.ignore();
            getline(cin, term);
            cout << "Enter definition for this term: ";
            cin.ignore();
            getline(cin, definition);
            ht.addTermin(term, definition);
            break;
        case 2:
            cout << "Enter term to remove: ";
            cin.ignore();
            getline(cin, term);
            ht.removeTermin(term);
            break;
        case 3:
            cout << "Enter term to find: ";
            cin.ignore();
            getline(cin, term);
            indexFind = ht.findTermin(term);
            if (indexFind < 20)
                cout << "The term exists under the number " << indexFind << endl;
            else
                cout << "There is no such term" << endl;
            break;
        case 4:
            ht.printHashTable();
            break;
        case 5:
            start = false;
            break;
        default:
            cout << "Try again\n";
            break;
        }
    }
    return 0;
}


// Abscissa - one of the Cartesian coordinates of a point, usually the first, denoted by the letter.
// Adjacent angles - angles in which one side is common and the other sides lie on the same straight line.
// Angle - a geometric figure consisting of two different rays coming from the same point.
// Axiom - a basic proposition, a self-evident principle, a proposition accepted without proof.
// Cathetus - the side of a right triangle adjacent to the right angle. 
// Constant - a value that keeps the same value in a particular task.
// Diameter - the chord passing through its (its) centre; length is equal to twice the radius. 
// Divisible - an expression, object, number that undergoes the process of division. 
// Divisor - an expression, object, number with which the division operation is performed. 
// Formula - a combination of mathematical signs (symbolic notation) in the form of an expression, equality or inequality containing some information.
// Hypotenuse - the side of a right triangle lying against a right angle. 
// Infinity ⎯ a concept introduced as an opposition to the concept of finite. 
// Integer - a number that can be represented as the difference of natural numbers.
// Lemma - an auxiliary proposition that is a true statement used in proving other statements (theorems).
// Limit - one of the basic concepts of mathematics, meaning that some variable in the process of its change is unrestrictedly approaching some constant value. 
// Mantissa - the fractional part of the decimal logarithm of a positive number.
// Mathematics - the science of quantitative relations and spatial forms of the actual world.
// Natural number - any of all positive integers of the set N.
// Ordinate - one of the Cartesian coordinates of a point, usually the second, denoted by the letter y.
// Parallelepiped - a hexagon whose opposite faces are pairwise parallel and represent pairwise equal parallelograms. 
// Periodic fraction - an infinite decimal fraction in which, starting from some place, there is a periodically repeating certain group of digits (period).
// Prism - a polyhedron whose two faces are n-gons (bases) and the other n faces (sides) are parallelograms.
// Rank of a matrix - the highest order of the nonzero determinant constructed from the elements of the given matrix.
// Ray - a set of points of a line lying on one side of some point of this line, including the point.
// Set - a aggregate, collection of any objects, called its elements, having a characteristic property common to them.
// Stereometry - a part of elementary geometry that studies the properties of figures arranged in space.
// Theorem - a proposition (statement) whose truth is proved.
// Vertical angles ⎯ pairs of angles with a common vertex formed by the intersection of two straight lines such that the sides of one angle are extensions of the sides of the other.  
