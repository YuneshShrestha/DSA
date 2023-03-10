class HuffmanNode {
  int data;
  String c;
  HuffmanNode? left, right;

  HuffmanNode(this.data, this.c, {this.left, this.right});
}

int bitCount = 0, totalBitCost = 0;
void printCode(HuffmanNode root, String s) {
  if (root.left == null &&
      root.right == null &&
      root.c.toLowerCase() != root.c.toUpperCase()) {
    print('${root.c} : $s');
    bitCount += s.length;
    totalBitCost += (s.length * root.data);
    return;
  }
  // Visit 1st left path and then right path
  printCode(root.left!, '$s' + '0');
  printCode(root.right!, '$s' + '1');
}

void main() {
  Map<String, int> data = {
    'a': 20,
    'b': 1,
    'c': 2,
    'd': 30,
    'e': 15,
    'f': 10,
    'G': 25,
    'H': 3
  };
  var q = <HuffmanNode>[];
  data.forEach((key, value) {
    q.add(HuffmanNode(value, key));
  });
  HuffmanNode? root;
  q.sort((a, b) => a.data - b.data);

  while (q.length > 1) {
    // Remove 1st two small value
    var x = q.removeAt(0);
    var y = q.removeAt(0);
    // Adding the removed values and storing in new root with character *
    var newRoot = HuffmanNode(x.data + y.data, '*');
    // Adding the removed values to left and right of the new root
    newRoot.left = x;
    newRoot.right = y;
    // Newly formed root is declared as root
    root = newRoot;
    // adding the new root at list q
    q.add(newRoot);
    // sort and repeat until legth=1
    q.sort((a, b) => a.data - b.data);
  }

  printCode(root!, '');
  print(
      "Total Bit :$bitCount, Total Bit Cost: $totalBitCost , Total Characters: ${data.length}\nSo, Total Cost: ${totalBitCost + (data.length * 8) + bitCount}");
}
