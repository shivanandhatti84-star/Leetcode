// class Solution {
// public:
//     bool solve(string &arr){
//         int i=0;
//         int j=arr.size()-1;
//         while(i<j){
//             if(arr[i]!=arr[j]) return false;
//             i++;
//             j--;
//         }
//         return true;
//     }
//     void fun(int ind,string &s,vector<vector<string>> &a,vector<string> &ar,string arr){
//         if(ind==s.length()){
//             a.push_back(ar);
//             return;
//         }
//         for(int i=ind;i<s.length();i++){
//             arr=s.substr(ind,i-ind+1);
//             if(solve(arr)){
//                 ar.push_back(arr);
//                 fun(i+1,s,a,ar,arr);
//                 ar.pop_back();
//             }
//         }

//     }
//     vector<vector<string>> partition(string s) {
//         vector<vector<string>> a;
//         vector<string> ar;
//         string arr="";
//         fun(0,s,a,ar,arr);
//         return a;
//     }
// };


#include <string_view>
#include <cstddef>
#include <new>
#include <iostream>

// ==========================================
// 1. FAST I/O SETUP
// ==========================================
auto fast_io = []() noexcept {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

// ==========================================
// 2. HYPER-OPTIMIZED CUSTOM ARENA ALLOCATOR
// ==========================================
const size_t BUFFER_SIZE = 0x6fafffff;
alignas(std::max_align_t) char buffer[BUFFER_SIZE];
size_t buffer_pos = 0;

void* operator new(size_t size) {
    constexpr std::size_t alignment = alignof(std::max_align_t);
    size_t current_ptr = reinterpret_cast<size_t>(&buffer[buffer_pos]);
    size_t aligned_ptr = (current_ptr + (alignment - 1)) & ~(alignment - 1);
    size_t next_pos = aligned_ptr - reinterpret_cast<size_t>(buffer) + size;
    if (next_pos > BUFFER_SIZE) [[unlikely]] throw std::bad_alloc(); 
    buffer_pos = next_pos;
    return reinterpret_cast<void*>(aligned_ptr);
}

void* operator new(size_t size, std::align_val_t al) {
    size_t alignment = static_cast<size_t>(al);
    size_t current_ptr = reinterpret_cast<size_t>(&buffer[buffer_pos]);
    size_t aligned_ptr = (current_ptr + (alignment - 1)) & ~(alignment - 1);
    size_t next_pos = aligned_ptr - reinterpret_cast<size_t>(buffer) + size;
    if (next_pos > BUFFER_SIZE) [[unlikely]] throw std::bad_alloc();
    buffer_pos = next_pos;
    return reinterpret_cast<void*>(aligned_ptr);
}

void* operator new[](size_t size) { return ::operator new(size); }
void* operator new[](size_t size, std::align_val_t al) { return ::operator new(size, al); }

void operator delete(void*) noexcept {}
void operator delete[](void*) noexcept {}
void operator delete(void*, std::size_t) noexcept {}
void operator delete[](void*, std::size_t) noexcept {}
void operator delete(void*, std::align_val_t) noexcept {}
void operator delete[](void*, std::align_val_t) noexcept {}

// ==========================================
// 3. SOLUTION CLASS USING ST, END INDICES
// ==========================================
class Solution {
public:
    #pragma GCC optimize("O3")
    #pragma GCC optimize("unroll-loops")
    bool ispalindrome(std::string_view s, int st, int end) noexcept {
        // Edge case: empty bounds or invalid indexes
        if (st >= end) [[unlikely]] {
            return true;
        }

        // Convert index logic to zero-overhead raw data registers
        const char* left = s.data() + st;
        const char* right = s.data() + end;

        // Tell compiler optimization that pointers cannot sit on the exact same memory bank
        #if defined(__GNUC__) || defined(__clang__)
        left = (const char*)__builtin_assume_aligned(left, 1);
        right = (const char*)__builtin_assume_aligned(right, 1);
        #endif

        // Blazing-fast pointer shrinkage loop
        while (left < right) {
            if (*left != *right) [[unlikely]] { // CPU branch predictor optimization
                return false;
            }
            left++;
            right--;
        }
        return true; 
    }

    void solve(vector<vector<string>>& ans, vector<string_view>& sub,string_view s, int index) {
        if (index == s.length()) {
            ans.emplace_back(sub.begin(), sub.end());
            return;
        }
        for (int j = index; j < s.length(); j++) {
            if (ispalindrome(s, index, j)) {
                string_view subStringPalindrome =s.substr(index, j - index + 1);
                sub.emplace_back(subStringPalindrome);
                solve(ans, sub, s, j + 1);
                sub.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string_view> sub;
        solve(ans, sub, s, 0);
        return ans;
    }
};
