# Normalized Compression Distance (NCD)

Normalized Compression Distance (NCD) is an approach that is used for clustering. It's based on algorithmic complexity developed by Kolmogorov, called Normalized Information Distance (NID). NCD can be used to cluster objects of any kind, such as music, texts, or gene sequences. Another area is plagiarism detection where it can measure the similarity between two strings. This application uses LZW (Lempel–Ziv–Welch) Text Compression method to calculate the NCD value.

Suppose we have two string sequences X and Y, and the concatenated sequence XY, The similarity between these two strings is to be computed with the use of Normalized Compression Distance (NCD) where the LZW text compression method is used. NCD is a non-negative number that ranges from 0 to 1, representing how different the two
token sequences are. The more different the two strings, the higher the ncd value is.


## Dependencies
This is a Qt GUI application project written in C++. You will need:
- MinGW (for Windows)
- GCC (for Linux)

## Get Source
```
git clone https://github.com/saebnaser/Normalized-Compression-Distance-NCD-.git

```

# Read more
- https://en.wikipedia.org/wiki/Lempel%E2%80%93Ziv%E2%80%93Welch
- https://en.wikipedia.org/wiki/Normalized_compression_distance

# Image

![NCD](https://user-images.githubusercontent.com/56490771/160769046-951ee6b9-bd31-4e2e-9eb6-cef90f14ed04.PNG)
