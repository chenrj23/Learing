//因为原题中在列表中存的都是对象，所以一般的比较都不行了，新增了几个方法，都是涉及到对象比较问题的。
function checkIn(name, movie, filmList, borrowedList){
    var temp = {
      name = name;
      movie = movie;
    }

    if (borrowedList.containsObj(temp) ) {
        filmList.append(temp);
        borrowedList.removeObj(temp);
    }
    else {
        print(movie + " is not borrowed.");
    }
}

function isObjectValueEqual(a, b) {
    // Of course, we can do it use for in 
    // Create arrays of property names
    var aProps = Object.getOwnPropertyNames(a);
    var bProps = Object.getOwnPropertyNames(b);

    // If number of properties is different,
    // objects are not equivalent
    if (aProps.length != bProps.length) {
        return false;
    }

    for (var i = 0; i < aProps.length; i++) {
        var propName = aProps[i];

        // If values of same property are not equal,
        // objects are not equivalent
        if (a[propName] !== b[propName]) {
            return false;
        }
    }

    // If we made it this far, objects
    // are considered equivalent
    return true;
}

function containsObj(element) {
    for (var i = 0; i < this.dataStore.length; ++i) {
        if (isObjectValueEqual(this.dataStore[i],element)) {
            return true;
        }
    }
    return false;
}
function findObj(element) {
    for (var i = 0; i < this.dataStore.length; ++i) {
        if (isObjectValueEqual(this.dataStore[i],element)) {
            return i;
        }
    }
    return -1;
}
function removeObj(element) {
    var foundAt = this.findObj(element);
    if (foundAt > -1) {
        this.dataStore.splice(foundAt,1);
        --this.listSize;
        return true;
    }
    return false;
}