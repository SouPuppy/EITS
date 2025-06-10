## HoTT Kernel

### Structure

- **Expression**
	- Term — Expressions that can be evaluated
	- Type — Classifiers for terms
	- Universe — Cumulative type hierarchy (e.g., `𝒰₀ : 𝒰₁`)
- **Variable** — Identifier
- **Value**
	- Const — Fully evaluated constants (e.g., natural numbers)	
	- Closure — Lambda closures with environment bindings
	- Neutral — Stuck computations (e.g., free variables or unevaluated terms)
- **Context (Γ)** — Typing environment (Γ), tracking variable bindings
- **Environment (ρ)** — Runtime environment (ρ), for evaluation and closures

### Types

- **Pi / Π (Function Type)**
- **Sigma / Σ (Dependent Pair)**
- **Id (Identity Type / Path)**

### Constructor

- λ-Abstraction — Introduction: `λx. t`
- Pairing — Introduction: `⟨a, b⟩`
- `refl` — Reflexivity path constructor

### Eliminator

- Application — Elimination: `f a`
- Projection — Elimination: `.$1`, `.$2`
- `J` — Path induction eliminator

### Runtime

- **Context Manager**
	- `#reset` — Clear all definitions and context
	- `#context` — Show the current typing context
- **Evaluation & Reduction**
	- `#eval` — Evaluate a term to weak-head normal form (WHNF)
	- `#norm` — Fully normalize a term
	- `#type` — Perform type inference or checking
	- `#quote` — Reify a value back into syntax
- **Utils**
	- `#save` / `#load` — Save/load the current session or context
	- `#exit` — Exit the runtime

---

**`#def`**

```
def id := λx. x
def two := (λf. λx. f (f x))
#context
```

```
Γ := {
  id ↦ λx. x,
  two ↦ (λf. λx. f (f x))
}
```

**`el`**

```
El(𝒰₀, ⟦Nat⟧)
```