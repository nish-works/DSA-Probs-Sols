int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] <= arr[high])
        {
            if (x > arr[mid] && x > arr[high])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if (x < arr[mid] && x > arr[low])
                high = mid - 1;
            else
                low = mid + 1;
        }
    }
    return -1;