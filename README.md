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
        high = mid - 1; // or low = mid + 1
    }
    else
    {
        low = mid + 1; // or high = mid - 1
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
- For each midpoint:
  - If `mid * mid == n`, return `mid`.
  - If `mid * mid < n`, search in the right half.
  - Otherwise, search in the left half.
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
- Use binary search on this search space.
- Create a helper function to:
  - Compute `midⁿ`.
  - Return:
    - `1` if `midⁿ == m`
    - `0` if `midⁿ < m`
    - `2` if `midⁿ > m`
- Based on the result, move the binary search boundaries.
- Return the exact root if it exists; otherwise return `-1`.

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

- We need to find the minimum eating speed `k` such that Koko can finish all banana piles within `h` hours.
- The answer lies in the range:
  - Minimum speed = `1`
  - Maximum speed = `max(piles)`
- For a chosen speed `mid`:
  - Calculate the total hours required to eat all piles.
  - For each pile:

```cpp
hours += ceil((double)pile / mid);
```

- If the required hours are less than or equal to `h`, then this speed is valid, and we try to find a smaller valid speed.
- Otherwise, we need a larger speed.

#### Monotonic Property

- If Koko can finish all bananas at speed `k`, then she can also finish them at any speed greater than `k`.

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

- We need to find the minimum number of days required to make `m` bouquets.
- Each bouquet requires `k` adjacent flowers.
- The answer lies between:
  - Minimum bloom day in the array.
  - Maximum bloom day in the array.
- For a chosen day `mid`:
  - Count the flowers that have bloomed by that day.
  - Form bouquets using consecutive bloomed flowers.
- If at least `m` bouquets can be formed:
  - Try a smaller day.
- Otherwise:
  - Increase the day.

#### Monotonic Property

- If it is possible to make `m` bouquets on day `d`, then it is also possible on any day greater than `d`.

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

- We need to find the smallest divisor such that:

```text
Σ ceil(arr[i] / divisor) ≤ threshold
```

- The answer lies between:
  - `1`
  - `max(arr)`
- For a chosen divisor `mid`:
  - Compute the sum of all ceiling divisions.
- If the sum is within the threshold:
  - Try a smaller divisor.
- Otherwise:
  - Increase the divisor.

#### Monotonic Property

- As the divisor increases, the total sum decreases or remains the same.
- This monotonic behavior makes Binary Search on Answers applicable.

#### Time Complexity

```text
O(n × log(max(arr)))
```

#### Space Complexity

```text
O(1)
```
### 6. Capacity to Ship Packages Within D Days

**File:** `codes/capacitytoshipwithinddays.cpp`

#### Approach

- We need to find the minimum ship capacity such that all packages are shipped within `D` days.
- The answer lies between:
  - Maximum weight in the array (minimum possible capacity).
  - Sum of all package weights (maximum possible capacity).
- Use binary search on this range.
- For a chosen capacity `mid`:
  - Simulate the shipping process.
  - Keep loading packages until adding the next package exceeds the capacity.
  - Start a new day whenever the capacity is exceeded.
- Count the total number of days required.
- If the required days are less than or equal to `D`:
  - The capacity is valid.
  - Try to find a smaller valid capacity.
- Otherwise:
  - Increase the capacity.

#### Monotonic Property

- If a ship capacity `C` can deliver all packages within `D` days, then any capacity greater than `C` can also deliver them within `D` days.

#### Time Complexity

```text
O(n × log(sum(weights)))
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
- Recognizing common Binary Search on Answers patterns used in coding interviews.

---

## 🚀 Source

- Striver's A2Z DSA Sheet
- Binary Search on Answers Pattern
