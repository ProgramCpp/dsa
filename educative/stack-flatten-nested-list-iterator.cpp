#include "NestedDirectory.cpp"

class NestedIterator
{
    // DO NOT flatten out all at once
    // flatten as and when the function is called
    // can be done with queues?
    stack<NestedDirectory *> allDirs;
    public:
        NestedIterator(vector<NestedDirectory *> nestedList)
        {
            for (auto subDir=nestedList.end()-1; subDir >= nestedList.begin(); subDir--){
                    allDirs.push(*subDir);
                }
        }

        bool HasNext()
        {
            return !allDirs.empty();
        }

        int Next()
        {

            NestedDirectory *d = allDirs.top();
            while (d != NULL && !d->isFile()){
                allDirs.pop();
                auto subDirs = d->getList();
                if (subDirs.size()){
                    for (auto subDir=subDirs.end()-1; subDir >= subDirs.begin(); subDir--){
                        allDirs.push(*subDir);
                    }
                }
                d = allDirs.top();
            }
            allDirs.pop();
            return d->getFile();
        }
};
