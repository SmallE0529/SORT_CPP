class Solution {
public:
    void swap(int *a, int *b)
    {
        int temp = *a;

        *a = *b;
        *b = temp;
    }

    //BUBBLE SORT
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

    //INSERT SORT
    void insert_sort(vector<int>& nums)
    {
        int len = nums.size();

        for(int i = 1 ; i < len ; i++)
        {
            int key = nums[i];
            int j = i - 1;

            while(j >= 0 && nums[j] > key)
            {
                nums[j+1] = nuWms[j];
                j--;
            }
            nums[j+1] = key;
        }
    }

    //SELECTION SORT
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
    
    //QUICK SORT
    /*int pratition(vector<int>& nums, int l, int r)
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
    }*/
    
    void quick_sort(vector<int>& nums, int l, int r)
    {
        if(l >= r)
        {
            return;
        }

        int pivot = l;

        for(int i = l ; i <= r-1 ; i++)
        {
            if(nums[i] < nums[r])
            {
                swap(&nums[pivot], &nums[i]);
                pivot++;
            }
        }

        swap(&nums[pivot], &nums[r]);
        quick_sort(nums, l, pivot - 1);
        quick_sort(nums, pivot + 1,  r);
    }

    //MERGE SORT
    /*void merge(vector<int>& nums, int l, int mid, int r)
    {
        int idx_l = 0;
        int idx_r = 0;
        vector<int> sub_l(nums.begin() + l, nums.begin() + mid + 1);
        vector<int> sub_r(nums.begin() + mid + 1, nums.begin() + r + 1);

        sub_l.insert(sub_l.end(), INT_MAX);
        sub_r.insert(sub_r.end(), INT_MAX);
                
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
    }*/

    void merge(vector<int>& nums, int l, int mid, int r)
    {
        vector<int>temp(r - l + 1);
        int i = l;
        int j = mid + 1;
        int k = 0;

        while(i <= mid && j <= r)
        {
            if(nums[i] < nums[j])
            {
                temp[k++] = nums[i++];
            }
            else
            {
                temp[k++] = nums[j++];
            }
        }

        while(i <= mid)
        {
            temp[k++] = nums[i++];
        }

        while(j <= r)
        {
            temp[k++] = nums[j++];
        }

        for(int i = 0 ; i < k ; i++)
        {
            nums[l + i] = temp[i];
        }
    }
    
    void merge_sort(vector<int>& nums, int l, int r)
    {
        if(l >= r)
        {
            return; 
        }

        int mid = l + (r - l)/2;

        merge_sort(nums, l , mid);  
        merge_sort(nums, mid + 1 , r);
        merge(nums, l, mid, r);
    }

    //HEAP SORT
    void maxheap(vector<int>& nums, int root, int len)
    {
        int biggest = root;
        int l = 2*root + 1;
        int r = 2*root + 2;

        if(len > l && nums[biggest] < nums[l])
        {
            biggest = l;  
        }

        if(len > r && nums[biggest] < nums[r])
        {
            biggest = r;
        }

        if(biggest != root)
        {
            swap(&nums[root], nums[biggest]);
            maxheap(nums, biggest, len);
        }
    }

    void heap_sort(vector<int>& nums)
    {
        int len = nums.size();

        for(int i = (len/2) - 1 ; i >= 0 ; i++)
        {
            maxheap(nums, i, len);
        }

        for(int i = len - 1 ; i > 0 ; i++)
        {
            wap(&nums[i], nums[0]);
            maxheap(nums, 0, i);
        }
    }

    //BUCKET SORT
    void bucket_rort(vector<int>& nums)
    {
        int len = nums.size();
        int k = 0;
        map<int, int> temp;
        map<int, int>::iterator it;

        for(int i = 0 ; i < len ; i++)
        {
            temp[nums[i]]++;
        }

        for(auto it = temp.begin() ; it != temp.end() ; it++)
        {
            int cnt = it->second;
            for(int i = 0 ; i < cnt ; i++)
            {
                nums[k++] = it->first;
            }
        }
    }

    vector<int> sortArray(vector<int>& nums)
    {
        int len = nums.size();

        //bubble_sort(nums);
        //insert_sort(nums);
        select_sort(nums);
        //quick_sort(nums, 0, len-1);
        //merge_sort(nums, 0, len-1);
        //heap_sort(nums);
        //bucket_sort(nums);

        return nums;
    }
};
