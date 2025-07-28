#include <iostream>
#include <vector>
#include <string>
#include <bitset> // For std::bitset
#include <cstring> // For memset

// Using a constant for max N for bitset size.
const int MAXN_BITSET = 3000;

// Global variables for grid dimensions and character count.
int N_grid, K_chars;

// Store the grid as characters.
char grid_data[MAXN_BITSET][MAXN_BITSET];

// Array of bitsets for each character.
// char_bitsets[char_idx][row_idx][col_idx] is 1 if grid_data[row_idx][col_idx] == ('A' + char_idx).
std::bitset<MAXN_BITSET> char_bitsets[26][MAXN_BITSET];

// Results for each character (true if a valid subgrid is found).
bool ans[26];

int main() {
    // Optimize C++ standard streams for competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> N_grid >> K_chars;

    // Read the grid input and populate the bitsets.
    for (int r = 0; r < N_grid; ++r) {
        for (int c = 0; c < N_grid; ++c) {
            std::cin >> grid_data[r][c];
            // Set the corresponding bit in the bitset for this character and row.
            char_bitsets[grid_data[r][c] - 'A'][r][c] = 1;
        }
    }

    // Iterate through each of the first K uppercase letters.
    for (int char_idx = 0; char_idx < K_chars; ++char_idx) {
        // If a valid subgrid has already been found for this character, skip it.
        if (ans[char_idx]) {
            continue;
        }

        // Iterate through all unique pairs of rows (r1, r2).
        for (int r1 = 0; r1 < N_grid; ++r1) {
            for (int r2 = r1 + 1; r2 < N_grid; ++r2) {
                // Perform a bitwise AND operation on the bitsets for rows r1 and r2 for the current character.
                // The .count() method returns the number of set bits (i.e., common columns).
                int common_cols_count = (char_bitsets[char_idx][r1] & char_bitsets[char_idx][r2]).count();

                // If there are at least two common columns, a valid subgrid is found.
                // The height (r2 - r1) is at least 1, and width (implied by common_cols_count >= 2) is at least 1.
                // This satisfies the "height and width is at least two" requirement as r2 > r1 and there are distinct columns c1, c2.
                if (common_cols_count >= 2) {
                    ans[char_idx] = true;
                    // Break out of the inner loops for r1 and r2 since we found a subgrid for this character.
                    goto found_for_char; // Use goto to break out of nested loops efficiently.
                }
            }
        }
        found_for_char:; // Label for goto.
    }

    // Print the results for each character.
    for (int i = 0; i < K_chars; ++i) {
        if (ans[i]) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }

    return 0;
}