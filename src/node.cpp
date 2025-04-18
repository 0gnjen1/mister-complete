#include "../include/node.h"

namespace Mistercomplete {

        int Node::child_count()
        {
                int count = 0;
                for(int i=0; i<26; i++) count += (children[i]!=0);
                return count;
        }

} // end namespace Mistercomplete
