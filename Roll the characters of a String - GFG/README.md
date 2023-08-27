# Roll the characters of a String
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given a string <strong>S</strong> and an array roll where <strong>roll[i]</strong> represents rolling first <strong>roll[i]</strong> characters in the string, the task is to apply every roll[i] on the string and output the final string. Rolling means increasing the ASCII value of character, like rolling z would result in a, rolling b would result in c, etc.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong> s = "bca"
roll[] = {1, 2, 3} <strong>
</strong><strong>Output:</strong> eeb
<strong>Explanation</strong>: arr[0] = 1 means roll 
first character of string -&gt; cca
arr[1] = 2 means roll 
first two characters of string -&gt; dda
arr[2] = 3 means roll
first three characters of string -&gt; eeb
So final ans is "eeb".</span></pre>

<p><span style="font-size:18px">&nbsp;<br>
<strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: </strong>s = "zcza"
roll[] = {1, 1, 3, 4}
<strong>Output: </strong>debb</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
This is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function <strong>findRollOut</strong>() that takes String<strong>&nbsp;S, </strong>array<strong> roll, </strong>and integer<strong> N&nbsp;</strong>as parameters and returns the modified string.<br>
<br>
<strong>Note-</strong> The length of the array roll and length of the string are equal.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(N).&nbsp;<br>
<strong>Expected Auxiliary Space:</strong> O(N).</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 10<sup>7</sup></span></p>
</div>