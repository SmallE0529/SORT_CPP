class Solution {
public:
    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    
    
    void bubble_sort(vector<int>& nums)
    {
        int len = nums.size();
        
        while(len > 0)
        {
            for(int i = 0; i < len - 1 ; i++)
            {
                if(nums[i] > nums[i+1])
                {
                    swap(&nums[i], &nums[i+1]);
                } 
            }
            len--;
        }
    }
    
    void insert_sort(vector<int>& nums)
    {
        int len = nums.size();
        for(int i = 1 ; i < len ; i++)
        {
            int key = nums[i];
            int j = i - 1;
            
            while(j >= 0 && nums[j] > key)
            {
                nums[j+1] = nums[j];
                j--;
            }
            nums[j+1] = key;
        }
    }
    
    int pratition(vector<int>& nums, int l, int r)
    {
        int pivot = nums[r];
        int j = l - 1;
        for(int i = l ; i < r ; i++)
        {
            if(pivot > nums[i])
            {
                j++;
                swap(&nums[i], &nums[j]);
            }
        }
        j++;
        swap(&nums[j], &nums[r]);
        return j;
    }
    
    
    void quick_sort(vector<int>& nums, int l, int r)
    {
        if(l < r)
        {
            int pivot = pratition(nums, l, r);
            quick_sort(nums, l, pivot - 1);
            quick_sort(nums, pivot + 1,  r);
        }
        
    }
    
    void heap_sort(vector<int>& nums)
    {
        int len = nums.size();
    }
    
    void merge(vector<int>& nums, int l, int mid, int r)
    {
        vector<int> sub_l(nums.begin() + l, nums.begin() + mid + 1);
        vector<int> sub_r(nums.begin() + mid + 1, nums.begin() + r + 1);

        sub_l.insert(sub_l.end(), INT_MAX);
        sub_r.insert(sub_r.end(), INT_MAX);
        
        int idx_l = 0;
        int idx_r = 0;
        
        for (int i = l; i <= r; i++) 
        {
            if(sub_l[idx_l] < sub_r[idx_r])
            {
                nums[i] = sub_l[idx_l];
                idx_l++;
            }
            else
            {
                nums[i] = sub_r[idx_r];
                idx_r++;
            }
        }
    }
    
    void merge_sort(vector<int>& nums, int l, int r)
    {
        if(l < r)
        {
            int mid = l + (r - l)/2;
            merge_sort(nums, l , mid);
            merge_sort(nums, mid + 1 , r);
            merge(nums, l, mid, r);
        }
    }
    
    void select_sort(vector<int>& nums)
    {
        int len = nums.size();
        for(int i = 0 ; i < len ; i++)
        {
            int min_idx = i;
            int min = nums[i];
            for(int j = i + 1 ; j < len ; j++)
            {   
                if(nums[j] < min)
                {
                    min_idx = j;
                }
            }
            swap(&nums[i], &nums[min_idx]);
        }
    }
    
    
    vector<int> sortArray(vector<int>& nums) {
        int len = nums.size();
        insert_sort(nums);
        bubble_sort(nums);
        select_sort(nums);    
        quick_sort(nums, 0, len-1);
        merge_sort(nums, 0, len-1);
        return nums;
    }
};