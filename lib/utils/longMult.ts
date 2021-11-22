export function longMult(a: string, b: string) {
    a = a.split("").reverse().join("");
    b = b.split("").reverse().join("");

    if (a.length < b.length) {
        [a, b] = [b, a];
    }

    let res: number[] = [],
        tmp = 0,
        lastIndex = a.length + b.length - 2;

    for (let i = 0; i < 100; i++) {
        res[i] = 0;
    }

    for (let i = 0; i < b.length; i++) {
        for (let j = 0; j < a.length; j++) {
            let mult = Number(a[j]) * Number(b[i]) + tmp;

            tmp = 0;
            let sum = res[i + j] + mult;
            res[i + j] = sum % 10;
            tmp = Math.floor(sum / 10);
        }

        if (tmp != 0) {
            res[i + a.length] += tmp;
            tmp = 0;
            if (i == b.length - 1) {
                lastIndex++;
            }
        }
    }

    let stringRes = "";
    for (lastIndex; lastIndex >= 0; lastIndex--) {
        stringRes += res[lastIndex];
    }
    return stringRes;
}
