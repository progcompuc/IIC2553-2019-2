#include <bits/stdc++.h>

using namespace std;

struct Block {
  int access_time;
  int block_number;

  Block() : access_time(-1), block_number(-1) {}
  Block(int t, int n) : access_time(t), block_number(n) {}

  bool operator<(const Block &other) const {
    if (access_time == other.access_time) {
      return block_number < other.block_number;
    }
    return access_time < other.access_time;
  }
};

const int T = 600;
int next_block = 1;

string line;

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  set<int> free_block_numbers;
  set<Block> allocated_blocks_time;
  map<int, Block> allocated_blocks_number;
  while (getline(cin, line)) {
    stringstream ss(line);
    int t;
    char op;
    ss >> t >> op;
    while (allocated_blocks_time.size() > 0 &&
           allocated_blocks_time.begin()->access_time + T <= t) {
      free_block_numbers.insert(allocated_blocks_time.begin()->block_number);
      allocated_blocks_number.erase(
          allocated_blocks_time.begin()->block_number);
      allocated_blocks_time.erase(allocated_blocks_time.begin());
    }
    if (op == '+') {
      int number;
      if (free_block_numbers.size() > 0) {
        number = *free_block_numbers.begin();
        free_block_numbers.erase(free_block_numbers.begin());
      } else {
        number = next_block;
        next_block += 1;
      }
      cout << number << '\n';
      Block block = Block(t, number);
      allocated_blocks_time.insert(block);
      allocated_blocks_number[number] = block;
    } else {
      int n;
      ss >> n;
      if (n < next_block &&
          free_block_numbers.find(n) == free_block_numbers.end()) {
        cout << '+' << '\n';
        Block &block = allocated_blocks_number[n];
        allocated_blocks_time.erase(block);
        block.access_time = t;
        allocated_blocks_time.insert(block);
      } else {
        cout << '-' << '\n';
      }
    }
  }
}