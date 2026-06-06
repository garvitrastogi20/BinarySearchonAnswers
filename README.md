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

- If Koko can finish all bananas at speed `k`,
  then she can also finish them at any speed greater than `k`.

This monotonic behavior makes Binary Search on Answers applicable.

#### Time Complexity

```text
O(n × log(max(piles)))
```

where:

- n = number of piles
- max(piles) = largest pile size

#### Space Complexity

```text
O(1)
```
## 🎯 Learning Outcomes

Through these problems, I learned:

Through these problems, I learned:

- How to identify a monotonic search space.
- Difference between Binary Search on Arrays and Binary Search on Answers.
- Designing efficient helper/check functions.
- Preventing overflow while computing powers.
- Applying binary search to mathematical problems.
- Solving optimization problems by minimizing or maximizing a valid answer.
- Using binary search with constraints involving time, speed, and capacity.

---

## 🚀 Source

- Striver's A2Z DSA Sheet
- Binary Search on Answers Pattern
