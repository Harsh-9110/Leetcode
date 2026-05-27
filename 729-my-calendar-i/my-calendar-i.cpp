class MyCalendar {
public:

    vector<pair<int,int>> books;

    MyCalendar() {

    }

    bool book(int start,
              int end) {

        for (auto& event : books) {

            int s = event.first;
            int e = event.second;

            // overlap exists
            if (start < e &&
                end > s) {

                return false;
            }
        }

        books.push_back({start, end});

        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */