#include "common.h"

std::unordered_map<std::string, std::string> replacement_table = {
	// Greek
	{" alpha", " α"},
	{" beta", " β"},
	{" gamma", " γ"},
	{" lambda", " λ"},

	// Capital Greek
	{" Gamma", " Γ"},
	{" Pi", " Π"},
	{" Sigma", " Σ"},

	// Math
	{" ->", " →"},
	{" =>", " ⇒"},
	{" times", " ×"},

	// Logic
	{" neg", " ¬"},
	{" false", " ⊥"},
	{" true", " ⊤"},

	// Set
	{" emptyset", " ∅"},
	{" in", " ∈"},
	{" notin", " ∉"},
	{" subset", " ⊂"},
	{" subseteq", " ⊆"},
	{" and", " ∩"},
	{" or", " ∪"},

	// Type Theory
	{" |-", " ⊢"}, {" vdash", " ⊢"},
	{" |=", " ⊨"}, {" models", " ⊨"},
	{" circ", " ∘"},

	// Special Math
	{" bbN", " ℕ"},
	{" bbZ", " ℤ"},
	{" bbQ", " ℚ"},
	{" bbR", " ℝ"},
	{" bbC", " ℂ"},
	{" bbP", " ℙ"},
	{" bbE", " 𝔼"},
};
