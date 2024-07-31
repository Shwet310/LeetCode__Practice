class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
         // Total number of books
        int numBooks = books.size();
      
        // Initialize the dynamic programming array which will store the minimum height for the first i books
        vector<int> dp(numBooks + 1);
      
        // Base case: no books means the shelves have a height of 0
        dp[0] = 0;
      
        // Loop through each book
        for (int i = 1; i <= numBooks; ++i) {
            // Width and height of the current book
            int currentWidth = books[i - 1][0], currentHeight = books[i - 1][1];
          
            // By default the minimum height after adding this book is its height plus the height of previous shelves without this book
            dp[i] = dp[i - 1] + currentHeight;
          
            // Try to place previous books on the same shelf with the current book to minimize the total height
            for (int j = i - 1; j > 0; --j) {
                // Accumulate the width with the previous book
                currentWidth += books[j - 1][0];
              
                // Break the loop if adding another book exceeds the shelf width
                if (currentWidth > shelfWidth) {
                    break;
                }
              
                // Update the current shelf's height based on the tallest book on this shelf
                currentHeight = max(currentHeight, books[j - 1][1]);
              
                // Determine the minimum height if this shelf configuration is used (place as many books as possible on the current shelf)
                dp[i] = min(dp[i], dp[j - 1] + currentHeight);
            }
        }
      
        // The last element in dp will have the minimum height by placing all books
        return dp[numBooks];
    }
};