var swap = function(array, firstIndex, secondIndex) {
    var temp = array[firstIndex];
	array[firstIndex] = array[secondIndex];
	array[secondIndex] = temp;
};

var testArray = [7, 9, 4];
swap(testArray, 0, 1);

println(testArray);

Program.assertEqual(testArray, [9, 7, 4]);

swap(testArray,0,2);
Program.assertEqual(testArray, [4, 7, 9]);
swap(testArray,0,2);
Program.assertEqual(testArray, [9, 7, 4]);