#Green Efficiency Analysis

##Measurement Methodology
	Three separate C programs were compiled using the required flags (-Wall -Werror -Wextra - pedantic -std=gnu89) and used to gather timing data: a baseline loop benchmark, a naive vs single-pass algorithm comparison, and a four-phase instrumentation lab. The timing was recorded using clock() from the <time.h> library, converting raw tick counts to seconds by dividing by CLOCKS_PER_SEC. The baseline loop and algorithm comparison were each done three times to check for run-to-run consistency. While the instrumentation lab was recorded once, producing a single breakdown of TOTAL, BUILD_DATA, PROCESS, and REDUCE phases. Also, averages and the relative-difference ratio were computed manually from the recorded run times. No algorithmic logic, data input, or timing boundaries were modified from the versions provided. 


##Observed Performance Differences
	The baseline loop (100,000,000 iterations) completed in 0.117839s, 0.112069s, and 0.113415s across three runs, averaging 0.114441 seconds, with less than 6 milliseconds of spread between the slowest and fastest run, consistent enough to treat as a stable baseline.
The algorithm comparison showed a far larger gap. The naive algorithm averaged 2.159056 seconds across three runs (2.154598s, 2.159318s, 2.163252s), while the single-pass algorithm averaged 0.0000853 seconds (0.000086s, 0.000085s, 0.000085s). With a difference of roughly 25,306×, with the single-pass version so fast it is close to the timing resolution of clock() itself on this system.
The instrumentation lab's single recorded run showed TOTAL at 0.000809s, split across BUILD_DATA (0.000421s), PROCESS (0.000223s), and REDUCE (0.000155s). These three sub-phases sum to 0.000799s, leaving roughly 0.00001s (10 microseconds) unaccounted for in TOTAL, possibly attributable to the small amount of code executing between each phase's timing boundaries. Within this breakdown, BUILD_DATA consumed the largest share, roughly 52% of total execution time, more than PROCESS and REDUCE combined.


##Relation Between Runtime and Energy Consumption
	No direct power or energy measurement was taken in any of these experiments — only wall-clock execution time via clock(). However, execution time is a reasonable proxy for relative energy use when comparing two implementations run on the same hardware under similar conditions: a CPU held at a given power draw for 2.16 seconds (naive) is doing substantially more sustained work, and very likely consuming substantially more energy, than one held at the same draw for 0.0000853 seconds (single-pass). Applied to the algorithm comparison, the ~25,306× runtime gap suggests the naive implementation carries a correspondingly large energy cost for equivalent work, assuming comparable power draw during execution. This inference is directional, not quantified — actual joules were never measured.


##Limitations of the Experiment
	Several limitations constrain how far these results can be generalised. 
First, clock() measures CPU time via a fixed tick resolution, not true wall-clock or energy-metered time; at the microsecond scale seen in the single-pass and instrumentation results, measurements approach the resolution limit of the timer itself, reducing precision. 
Second, only the baseline loop and algorithm comparison were run three times. The instrumentation lab was recorded only once, so its phase breakdown lacks any measure of run-to-run variance. 
Third, no dedicated power-measurement hardware or software was used, so all energy-related conclusions above are inferred from runtime alone, not directly observed. 
Fourth, the naive and single-pass algorithms returned different results (625025000 vs. 25000) on every run, indicating they were not verified to be solving the same problem correctly. A speed comparison between two implementations that disagree on output is informative but not fully conclusive. 
Finally, all measurements come from a single machine under unspecified background load, so absolute timings are not portable to other hardware.


##Practical Engineering Takeaway
	The clearest, best-supported finding across all three experiments is as follows: Algorithmic approach dominates micro-level code tuning as a factor in both runtime and, by inference, energy use. The ~25,306× gap between naive and single-pass approaches to the same input size vastly exceeds any plausible gain from low-level optimisation of the baseline loop, whose three runs varied by only a few milliseconds regardless. For real-world engineering, this suggests effort spent identifying a better algorithm (reducing computational complexity) will typically yield far greater efficiency and energy gains than effort spent fine-tuning an already suboptimal approach. Though this project's own data-mismatch limitation is a reminder to verify correctness before trusting a speed comparison at face value.
