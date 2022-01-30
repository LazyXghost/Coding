/* Generate number with given digits
    given digits -: [5,6]
    total no to generate = 10

           empty string
          /            \
        "5"            "6"
       /   \          /   \
     "55" "56"      "65"  "66"

    push 5,6 in queue
    whenever we pop no we print it
    then we push in it the no popped + "5","6"

   GOOD PROBLEMS-: 
   https://practice.geeksforgeeks.org/problems/circular-tour-1587115620/0/?track=DSASP-Queue&batchId=154#
 */