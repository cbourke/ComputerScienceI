



## Shallow Versus Deep Copies

* When references are copied, they are only *shallow* copies: changes to an array through one reference are "seen" by the second reference
* Alternatively: if you want a totally distinct copy, you want a *deep copy*: you want two completely different arrays stored in two completely different memory addresses.
* Use deep copies when you *don't* want changes to the original (or you want to retain the original data)

nt n = 5;
int *a = (int *) malloc(sizeof(int) * n);
for(int i=0; i<n; i++) {
  a[i] = (i+1) * 10;
}

int *b = a;
a[0] = 42;







  int n = 3;
  int m = 4;
  int **table = (int **) malloc(sizeof(int *) * n);
  for(int i=0; i<n; i++) {
    table[i] = (int *) malloc(sizeof(int) * m);
    for(int j=0; j<m; j++) {
      table[i][j] = (i+j+1) * 10;
    }
  }

  free(table)
