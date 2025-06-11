# EITS

### 1. Clone and enter the repo (or use HTTPS)

```
git clone git@github.com:SouPuppy/EITS.git
cd EITS
```

### 2. Create build directory and configure with verbose logging

```
mkdir build && cd build
cmake .. -DENABLE_LOG_VERBOSE=ON
```

### 3. Build only the REPL executable

```
cmake --build . --target eits_repl -- -j$(nproc)
```

### 4. Run the REPL

```
./eits-repl/src/eits_repl
```

## REPL Guide

Type `help` to list available commands:

```
In[1]: help

Available commands:

  def                       Define a named term
  eval                      Evaluate expression
  type                      Show type of expression
  context                   Show current context
  reset                     Clear all definitions
  edit                      Launch multi-line editor
  help                      Show this help message
  exit                      Exit the REPL

```

Multi-line Editing

```
In[5]: edit
[Launching editor...]
 0 | def compose := λf g x. f (g x)
 1 |

[Editor done.]
```

## Appendix: Symbol Replacement Table

The following text patterns are automatically replaced in the REPL (notice the space before the Input):

| Category      | Input Pattern | Replacement | Description             |
|---------------|---------------|-------------|-------------------------|
| **Greek**     | ` alpha`      | ` α`        | lower-case alpha        |
|               | ` beta`       | ` β`        | lower-case beta         |
|               | ` gamma`      | ` γ`        | lower-case gamma        |
|               | ` lambda`     | ` λ`        | lower-case lambda       |
| **Capital Greek** | ` Gamma`  | ` Γ`        | upper-case Gamma        |
|               | ` Pi`         | ` Π`        | upper-case Pi           |
|               | ` Sigma`      | ` Σ`        | upper-case Sigma        |
| **Math**      | ` ->`         | ` →`        | arrow                   |
|               | ` =>`         | ` ⇒`        | double arrow            |
|               | ` times`      | ` ×`        | multiplication          |
| **Logic**     | ` neg`        | ` ¬`        | negation                |
|               | ` false`      | ` ⊥`        | false (bottom)          |
|               | ` true`       | ` ⊤`        | true (top)              |
| **Set**       | ` emptyset`   | ` ∅`        | empty set               |
|               | ` in`         | ` ∈`        | element of              |
|               | ` notin`      | ` ∉`        | not element of          |
|               | ` subset`     | ` ⊂`        | strict subset           |
|               | ` subseteq`   | ` ⊆`        | subset or equal         |
|               | ` and`        | ` ∩`        | intersection            |
|               | ` or`         | ` ∪`        | union                   |
| **Type Theory** | ` \|-`      | ` ⊢`        | turnstile (provability) |
|               | ` vdash`      | ` ⊢`        | turnstile alternate     |
|               | ` \|=`        | ` ⊨`        | semantic entailment     |
|               | ` models`     | ` ⊨`        | semantic models         |
|               | ` circ`       | ` ∘`        | circle/composition      |
| **Special Math** | ` bbN`     | ` ℕ`        | natural numbers         |
|               | ` bbZ`        | ` ℤ`        | integers                |
|               | ` bbQ`        | ` ℚ`        | rationals               |
|               | ` bbR`        | ` ℝ`        | reals                   |
|               | ` bbC`        | ` ℂ`        | complex numbers         |
|               | ` bbP`        | ` ℙ`        | projective space        |
|               | ` bbE`        | ` 𝔼`        | expected value          |
