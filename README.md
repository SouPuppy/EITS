## HoTT Kernel

### Structure

- Expression
	- Term — Expressions that can be evaluated
	- Type — Classifiers for terms
	- Universe — Cumulative type hierarchy (e.g., `Type₀ : Type₁`)
- Value
	- Const — Fully evaluated constants (e.g., natural numbers)
	- Closure — Lambda closures with environment bindings
	- Neutral — Stuck computations (e.g., free variables or unevaluated terms)
- Context — Typing environment (Γ), tracking variable bindings
- Environment — Runtime environment (ρ), for evaluation and closures

### Constructor & Eliminator

- Pi / Π (Function Type)
	- Application — Elimination: `f a`
	- λ-Abstraction — Introduction: `λx. t`
- Sigma / Σ (Dependent Pair)
	- Projection — Elimination: `.1`, `.2`
	- Pattern Matching — Destructuring pairs
- W (Well-founded Inductive Types)
	- `w-ind` — Elimination rule for structural recursion
- Id (Identity Type / Path)
	- `refl` — Reflexivity path constructor
	- `J` — Path induction eliminator
	- `transport` — Apply type equivalence along paths
- HIT (Higher Inductive Types)
	- Point Constructors — Introduce values in HIT
	- Path Constructors — Introduce equalities between constructors
	- Higher Path Eliminators — Eliminate based on higher paths

### Axioms

- Univalence

### Runtime

- Context Manager
	- `#context` — Show the current typing context
	- `#reset` — Clear all definitions and context
- Evaluation & Reduction
	- `#eval` — Evaluate a term to weak-head normal form (WHNF)
	- `#norm` — Fully normalize a term
	- `#quote` — Reify a value back into syntax (NbE)
	- `#type` — Perform type inference or checking
- Eliminator Commands
	- `#elim pi` — Apply function types
	- `#elim sigma` — Project or match dependent pairs
	- `#elim w` — Perform recursion over inductive structures
	- `#elim id` / `#j` — Use path induction
	- `#elim hit` — Eliminate higher inductive types
- Utils
	- `#save` / `#load` — Save/load the current session or context
	- `#exit` — Exit the runtime
