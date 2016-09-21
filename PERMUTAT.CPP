 #include "../../C/UTILITY.H"
#include "../../C/UTILITY.CPP"
const int max_degree = 20;
 
void process_permutation(int *permutation)
/* 
 
Pre:  permutation is in linked form.
Post: The permutation has been printed to the terminal.
 
*/

{
   int current = 0;
   while (permutation[current] != 0) {
      cout << permutation[current] << " ";
      current = permutation[current];
   }
   cout << endl;
}
 
void permute(int new_entry, int degree, int *permutation)
/* 
 
Pre:  permutation contains a linked permutation with entries in positions
     1 through new_entry - 1.
Post: All permutations with degree entries, built from the given
     permutation, have been constructed and processed.
Uses: Functions permute (recursively) and process_permutation.
 
*/

{
   int current = 0;
   do {
      permutation[new_entry] = permutation[current];
      permutation[current] = new_entry;
      if (new_entry == degree)
         process_permutation(permutation);
      else
         permute(new_entry + 1, degree, permutation);
      permutation[current] = permutation[new_entry];
      current = permutation[current];
   } while (current != 0);
}
 
void main()
/* 
 
Pre:   The user specifies the degree of permutations to construct.
Post: All permutations of a user-supplied degree are printed to
      the terminal.
 
*/

{
   int degree;
   int permutation[max_degree + 1];

   cout << "Number of elements to permute? ";
   cin  >> degree;
 
   if (degree < 1 || degree > max_degree)
      cout << "Number must be between 1 and " << max_degree << endl;
   else {
      permutation[0] = 0;
      permute(1, degree, permutation);
   }
}
