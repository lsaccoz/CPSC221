generator0: like a base case. -> Inserts random numbers,
                              -> Finds those numbers (in a different random order)
                              -> Removes those numbers (in a different order).

generator1: {implements mtf. detailed description needed}

generator2: {implements sl. detailed description needed}


///////// ideas ////////

mtf:  test removing stuff after finding it.
      because the linked list is move to front
      on find. find would be O(n) and remove O(1).
      [So make a test suite that finds something
      and then removes it immediately.]

sl:   find is O(lg n). remove is O(lg n + (n - lg n)) = O(n).
      but if you remove the max_element at the end,
      remove is O(lg n).
      [So make a test filled with random elements.
      Then take out biggest elements in descending order.]

hch:  worst time insert is O(n) when putting a value
      that already exists in table. putting a seemingly
      unique sequence such as 1,2,3.. could give O(1) insertion.
      [------- NO TEST THOUGHT OF -------]

hqp:  since it resizes, it will always find a place to be
      insrted in. The worst time for this could be O(n)
      (e.g. when hash2() = 1, which is legitimate I guess).
      [------- NO TEST THOUGHT OF -------]

bstT: averages are all O(lg n) and worst cases are all O(n).
      [random generator should give all aproximately lg n,
      but another case would be to insert elements like
      1,2,3,4... which would yield all three O(n). This is
      similar to the sl test (combinations are good!)]

avl:  I guess same as above plus somethign else thats special
      about avl trees.

spt:  just like avl trees but makes recent insertions easier
      to find (by 'splaying'). Must use this to our advantage. 
