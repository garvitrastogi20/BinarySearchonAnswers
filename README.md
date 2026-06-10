# Binary Search on Answers

This repository contains my solutions to the **Binary Search on Answers** section from **Striver's A2Z DSA Sheet**.

The goal of this repository is to build a strong understanding of identifying monotonic search spaces and applying binary search to find optimal answers efficiently.

---

## 📚 Problems Solved

| S.No. | Problem | File |
|--------|----------|------|
| 1 | Square Root of a Number | [findingsqrt.cpp](./codes/findingsqrt.cpp) |
| 2 | Finding Nth Root of a Number | [findingnthrootofnumber.cpp](./codes/findingnthrootofnumber.cpp) |
| 3 | Koko Eating Bananas | [kokoeatingbananas.cpp](./codes/kokoeatingbananas.cpp) |
| 4 | Minimum Number of Days to Make m Bouquets | [mindaysformbouquets.cpp](./codes/mindaysformbouquets.cpp) |
| 5 | Find the Smallest Divisor Given a Threshold | [smallestdivisorgivenathreshold.cpp](./codes/smallestdivisorgivenathreshold.cpp) |
| 6 | Capacity to Ship Packages Within D Days | [capacitytoshipwithinddays.cpp](./codes/capacitytoshipwithinddays.cpp) |
| 7 | Kth Missing Positive Number (Linear Approach) | [kthmissingpositive.cpp](./codes/kthmissingpositive.cpp) |
| 8 | Kth Missing Positive Number (Binary Search Approach) | [kthmissingpositivestriver.cpp](./codes/kthmissingpositivestriver.cpp) |

---

## 🧠 Strategy: Binary Search on Answers

Binary Search on Answers is a technique used when:

- The search space consists of possible answers rather than array indices.
- A condition can determine whether a candidate answer is valid.
- The problem exhibits a monotonic property (if an answer works, all answers on one side also work).

### General Template

```cpp
int low = minimumPossibleAnswer;
int high = maximumPossibleAnswer;

while(low <= high)
{
    int mid = low + (high - low) / 2;

    if(check(mid))
    {
        // Store answer if required
        high = mid - 1;
    }
    else
    {
        low = mid + 1;
    }
}
```

---

## Problem-wise Approach

### 1. Square Root of a Number

**File:** `codes/findingsqrt.cpp`

#### Approach

- The square root of a number `n` lies between `1` and `n`.
- Use binary search on this range.
- If `mid * mid == n`, return `mid`.
- If `mid * mid < n`, search the right half.
- Otherwise, search the left half.
- Store the last valid value for the floor square root.

#### Time Complexity

```text
O(log n)
```

#### Space Complexity

```text
O(1)
```

---

### 2. Finding Nth Root of a Number

**File:** `codes/findingnthrootofnumber.cpp`

#### Approach

- The nth root of a number `m` lies between `1` and `m`.
- Use binary search on this range.
- Create a helper function to evaluate `midⁿ`.
- Return:
  - `1` if `midⁿ == m`
  - `0` if `midⁿ < m`
  - `2` if `midⁿ > m`
- Move the search space accordingly.
- Return the exact root if found, otherwise return `-1`.

#### Time Complexity

```text
O(n × log m)
```

#### Space Complexity

```text
O(1)
```

---

### 3. Koko Eating Bananas

**File:** `codes/kokoeatingbananas.cpp`

#### Approach

- Find the minimum eating speed `k` such that Koko finishes all bananas within `h` hours.
- Search space:
  - Minimum speed = `1`
  - Maximum speed = `max(piles)`
- For every speed `mid`, compute total hours needed.

```cpp
hours += ceil((double)pile / mid);
```

- If hours ≤ `h`, try a smaller speed.
- Otherwise, increase the speed.

#### Monotonic Property

- If speed `k` works, every speed greater than `k` also works.

#### Time Complexity

```text
O(n × log(max(piles)))
```

#### Space Complexity

```text
O(1)
```

---

### 4. Minimum Number of Days to Make m Bouquets

**File:** `codes/mindaysformbouquets.cpp`

#### Approach

- Find the minimum day required to make `m` bouquets.
- Search space:
  - Minimum bloom day
  - Maximum bloom day
- For a chosen day:
  - Count bloomed flowers.
  - Form bouquets using consecutive flowers.
- If at least `m` bouquets can be formed:
  - Try smaller days.
- Otherwise:
  - Increase the day.

#### Monotonic Property

- If bouquets can be formed on day `d`, they can also be formed on any day greater than `d`.

#### Time Complexity

```text
O(n × log(maxBloomDay))
```

#### Space Complexity

```text
O(1)
```

---

### 5. Find the Smallest Divisor Given a Threshold

**File:** `codes/smallestdivisorgivenathreshold.cpp`

#### Approach

- Find the smallest divisor such that:

```text
Σ ceil(arr[i] / divisor) ≤ threshold
```

- Search space:
  - `1`
  - `max(arr)`
- For each divisor:
  - Compute the sum of ceiling divisions.
- If the sum is within the threshold:
  - Try smaller divisors.
- Otherwise:
  - Increase the divisor.

#### Monotonic Property

- Increasing the divisor decreases or maintains the total sum.

#### Time Complexity

```text
O(n × log(max(arr)))
```

#### Space Complexity

```text
O(1)
```

---

### 6. Capacity to Ship Packages Within D Days

**File:** `codes/capacitytoshipwithinddays.cpp`

#### Approach

- Find the minimum ship capacity needed to deliver all packages within `D` days.
- Search space:
  - Maximum package weight
  - Sum of all package weights
- For a chosen capacity:
  - Simulate package loading.
  - Start a new day whenever capacity is exceeded.
- Count total days required.
- If days ≤ `D`:
  - Try a smaller capacity.
- Otherwise:
  - Increase the capacity.

#### Monotonic Property

- If capacity `C` works, any capacity greater than `C` will also work.

#### Time Complexity

```text
O(n × log(sum(weights)))
```

#### Space Complexity

```text
O(1)
```

---

### 7. Kth Missing Positive Number (Linear Approach)

**File:** `codes/kthmissingpositive.cpp`

#### Approach

- Traverse the array from left to right.
- If the current element is less than or equal to `k`, increment `k`.
- Continue until an element greater than `k` is found.
- The final value of `k` is the kth missing positive number.

#### Time Complexity

```text
O(n)
```

#### Space Complexity

```text
O(1)
```

---

### 8. Kth Missing Positive Number (Binary Search Approach)

**File:** `codes/kthmissingpositivestriver.cpp`

#### Approach

- Use binary search on the sorted array.
- For any index `i`:

```text
missing = arr[i] - (i + 1)
```

- This represents the count of missing positive numbers before `arr[i]`.
- If `missing < k`, move right.
- Otherwise, move left.
- After binary search completes:

```cpp
answer = low + k;
```

#### Monotonic Property

- The count of missing numbers increases monotonically as index increases.

#### Time Complexity

```text
O(log n)
```

#### Space Complexity

```text
O(1)
```

---

## 🎯 Learning Outcomes

Through these problems, I learned:

- How to identify a monotonic search space.
- Difference between Binary Search on Arrays and Binary Search on Answers.
- Designing efficient helper/check functions.
- Preventing overflow while computing powers.
- Applying binary search to mathematical problems.
- Solving optimization problems by minimizing or maximizing a valid answer.
- Using binary search with constraints involving time, speed, days, divisors, and capacity.
- Solving missing-number problems using both linear and binary search approaches.
- Using the formula `arr[i] - (i + 1)` to count missing elements efficiently.
- Optimizing an O(n) solution to O(log n) using Binary Search.
- Recognizing hidden monotonic patterns in sorted arrays.
- Recognizing common Binary Search on Answers patterns used in coding interviews.

---

## 🚀 Source

- Striver's A2Z DSA Sheet
- Binary Search on Answers Pattern

---

## ⭐ Repository Progress

**Problems Solved:** 8

This repository will continue to grow as I complete more Binary Search on Answers problems from Striver's A2Z DSA Sheet.
