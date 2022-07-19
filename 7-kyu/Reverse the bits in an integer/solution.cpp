unsigned int reverse_bits(unsigned int n) {
  unsigned result = 0;
  while(n != 0)
  {
    //shift result to the left and add the right most bit of n
    // better than result = result << 1 => overshift one bit => shift back to right but cause all 1s cause problem
    result = (result<<1) + (n&1);
    //shift to right
    n = n>>1;
  }
  return result;
}