int ff(int n) {
  if (n==0) {
    return 1;
  }  else {
    return ff(n - 1);
    printf("%d", n);
  }
}

int main() {
  printf("%d", ff(4));
}
