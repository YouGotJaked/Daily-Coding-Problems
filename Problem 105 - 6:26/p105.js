/*
 * Given a function f, and N return a debounced f of N milliseconds.
 * That is, as long as the debounced f continues to be invoked, f itself will not be called for N milliseconds.
 */

// returns a function that will be called after it stops being called for N milliseconds
function debounce(func, wait, immediate) {
    var timeout;
    
    return function() {
        var context = this, args = arguments;
        clearTimeout(timeout);
        timeout = setTimeout(function() {
            timeout = null;
            if (!immediate) func.apply(context, args);
        }, wait);
        if (immediate && !timeout) func.apply(context, args);
    };
};


