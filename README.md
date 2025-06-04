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

### Constructor & Eliminator

- **Pi / Π (Function Type)**
	- Application — Elimination: `f a`
	- λ-Abstraction — Introduction: `λx. t`
- **Sigma / Σ (Dependent Pair)**
	- Pairing — Introduction: `⟨a, b⟩`
	- Projection — Elimination: `.1`, `.2`
- **Id (Identity Type / Path)**
	- `refl` — Reflexivity path constructor
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

```
Machinish/
├── CMakeLists.txt
├── README.md
├── .clang-format
├── .clang-tidy
├── version.txt
│
├── cmake/                       # CMake 模块（版本号、构建配置）
│   ├── Version.cmake
│   └── template/version.hpp.in
│
├── include/
│   └── machinish/
│       ├── syntax/             # 🧠 语法层：构造表达式（Term, Type, Universe）
│       │   ├── term.hpp
│       │   ├── type.hpp
│       │   └── universe.hpp
│       │
│       ├── semantics/          # 🎯 语义层：值域、环境、消解器等
│       │   ├── value.hpp       # Const / Closure / Neutral
│       │   ├── env.hpp         # 环境 Env（运行时绑定）
│       │   ├── eliminator.hpp  # J、.1、.2 等
│       │   └── constructor.hpp # Π / Σ / Id 等
│       │
│       ├── context/            # 📘 类型系统相关
│       │   ├── context.hpp     # Γ，类型上下文
│       │   └── inference.hpp   # 类型推导
│       │
│       ├── runtime/            # ⚙️ 运行期命令与解释器
│       │   ├── command.hpp     # #eval, #norm, #type ...
│       │   └── repl.hpp        # 脚本驱动 / 交互执行
│       │
│       └── kernel.hpp          # 顶层入口与接口封装（可以初始化 VM、加载模块等）
│
├── src/
│   ├── syntax/
│   │   ├── term.cpp
│   │   ├── type.cpp
│   │   └── universe.cpp
│   │
│   ├── semantics/
│   │   ├── value.cpp
│   │   ├── env.cpp
│   │   ├── eliminator.cpp
│   │   └── constructor.cpp
│   │
│   ├── context/
│   │   ├── context.cpp
│   │   └── inference.cpp
│   │
│   ├── runtime/
│   │   ├── command.cpp
│   │   └── repl.cpp
│   │
│   ├── main.cpp                # CLI 主程序入口
│   └── kernel.cpp              # 顶层调度器实现（初始化、注册命令等）
│
├── demo/                       # 示例代码
│   ├── example_sigma.cpp
│   ├── example_identity.cpp
│   └── ...
│
├── tests/                      # 测试模块
│   ├── test_context.cpp
│   ├── test_typecheck.cpp
│   └── ...
│
├── docs/                       # 文档与设计说明
│   ├── kernel-design.md
│   ├── inductive-families.md
│   └── ...
│
└── scripts/                    # 构建 & 工具脚本
    ├── format.sh
    ├── version.sh
    └── run_tests.sh


eiminator和 constructor 不应该在一起吗 

内部的解耦 分别实现W J 等
```
